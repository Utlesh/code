/*
Thread Interrupts
----------------
Thread interrupts are used to
1) Bring a thread out of sleep
2) Bring a thread out of join
3) Bring a thread out of wait
4) Send terminate signal to another thread. (Doesnt cause termination).


*/


class TInterrupt1 implements Runnable
{
  Thread t;
  Thread handleToMain;

  TInterrupt1(Thread x)
  {
   handleToMain = x;
   t= new Thread(this);
   t.start();
  }

  public void run()
  {
   int i;
   for(i =0; i< 200; i++)
   {
    System.out.print(" T ");
    if(i == 40)
    {
     try
     {
       System.out.println("i plan to suspend until main gets over");
       handleToMain.join();
       System.out.println("i resume after main");
     }
     catch(InterruptedException ex)
     {
       System.out.println("Somebody interrupted my suspension"); 
     }
    }//if
   }//for
  }//run

  public static void main(String args[])
  {
    TInterrupt1 ti = new TInterrupt1(Thread.currentThread());
    int i;
    for(i =0; i< 1000; i++)
    {
      System.out.print(" M ");
      if(i == 500)
         ti.t.interrupt();//transmit interrupt signal to bring ti.t out of join

    }
   
    System.out.println("main complete");
  }
}