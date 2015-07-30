/*
Consider a case, when a thread that
owns a critical section realizes that
its next processing is possible only after
another thread completes its execution.

In such a scenario the thread that owns
the critical section must suspend ownself
and hence release the object monitor
ownership.

This will allow the other thread to enter
critical section, use the shared resource
and complete its task.

Finally the thread must transmit a
resume signal to the suspended thread.
If not notified the suspended thread
may get infinite suspension and cause
system deadlock.

*/

import java.util.Random;


class NumberHolder // extends Object
{
  int x;
  boolean flag; //false by default

  NumberHolder()
  {
    flag = false;
  }

  synchronized void setNumber(int q)
  {
    Thread t = Thread.currentThread();
    System.out.println(t.getName() + " in for setting a value ");

    if(flag == true)
    {//prev gen. value is not consumed yet
     //suspend ownself
     try
     {   
       wait();//infinite suspension until notified        
       //wait(10000);//suspension for specific time
     }
     catch(InterruptedException ex)
     {}
    } 

    x = q;
    flag = true;
    System.out.println(t.getName() + " has set the value " + x);
    notify(); //transmit resume signal to a waiting thread
    //notifyAll();//transmit resume signal to all waiting threads
 
  }

  synchronized void displayNumber()
  {
    Thread t = Thread.currentThread();
    System.out.println(t.getName() + " in for fetching the value ");

    if(flag == false)
    {//number is not generated yet
     //suspend ownself
     try
     {   
       wait();//infinite suspension until notified        
       //wait(10000);//suspension for specific time
     }
     catch(InterruptedException ex)
     {}
    }

    System.out.println("NUMBER : " + x);
    flag = false;//data consumed
    notify();//transmit resume signal to one waiting thread
    //notifyAll();//transmit resume signal to all waiting threads
  }

}//NumberHolder


class Writer extends Thread
{
 int times;
 NumberHolder svr;

 Writer(NumberHolder nh)
 {
   svr = nh; 
   setName("Writer");
   times = 10;
   start();
 }

 public void run()
 {
  int i, val;
  Random r = new Random(); //a random number generator

  for(i=0; i< times; i++)
  {
   val = r.nextInt(100);//generate a random Int in range 0-99
   svr.setNumber(val);
  }//for   
 }//run
}//Writer

class Reader extends Thread
{
 int times;
 NumberHolder svr;

 Reader(NumberHolder nh)
 {
   svr = nh;
   setName("Reader");
   times = 10;
   start();
 }

 public void run()
 {
  int i;
  for(i=0; i< times; i++)
  {
   svr.displayNumber();
  }//for   
 }//run
}//Reader

class ReaderWriter
{
 public static void main(String args[])
 {
  NumberHolder nh = new NumberHolder();
  Reader r = new Reader(nh);
  Writer w = new Writer(nh);

 }//main
}//ReaderWriter