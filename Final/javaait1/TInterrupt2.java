/*
Thread Interrupts
----------------
Thread interrupts are used to
1) Bring a thread out of sleep
2) Bring a thread out of join
3) Bring a thread out of wait
4) Send terminate signal to another thread. (Doesnt cause termination).


*/


class TInterrupt2 implements Runnable
{
  Thread t;

  TInterrupt2()
  {
   t= new Thread(this);
   t.start();
  }

  public void run()
  {
   int i;
   for(i =0; i< 1000; i++)
   {
    if(Thread.interrupted())//check for an incoming interrupt signal and if found rest it as well
    //if(t.isInterrupted())//check for an incoming interrupt signal
    {
      System.out.print(" * ");
    }
    System.out.print(" T ");
   }//for
 
   System.out.println("run complete");
  }//run

  public static void main(String args[])
  {
    TInterrupt2 ti = new TInterrupt2();
    int i;
    for(i =0; i< 100; i++)
    {
      System.out.print(" M ");
    }
    ti.t.interrupt();//transmit interrupt to signal termination

    System.out.println("main complete");
  }
}