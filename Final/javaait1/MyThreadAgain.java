/*
Implementing multithreading by defining
a class that 
* uses Thread object
* implements Runnable

*/

class MyThreadAgain implements Runnable
{
 Thread t;

 MyThreadAgain()
 {
  t = new Thread(this);//custom thread
  t.start();
 } 

 //One and only Runnable interface method 
 //Thread Life Cycle Method
 public void run()
 {
  int i;
  for(i =0 ; i< 200; i++)
    System.out.print(" T ");
 }

 public static void main(String args[])
 {
  MyThreadAgain mta = new MyThreadAgain();

  int i;
  for(i =0 ; i< 200; i++)
    System.out.print(" M ");

 }
}

/*
package java.lang;

public class Thread implements Runnable
{
 Runnable x;

 Thread()
 {
  x = this;
  ...
 }

 Thread(Runnable r)
 {
  x = r;
  ...
 }

 public void start()
 {
   thread activation
   ...
   x.run();
 }
 public void run()
 {} 

}





*/
