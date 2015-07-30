/*
Thread Interrupts
----------------
Thread interrupts are used to
1) Bring a thread out of sleep
2) Bring a thread out of join
3) Bring a thread out of wait
4) Send terminate signal to another thread. (Doesnt cause termination).


*/


class TInterrupt implements Runnable
{
  Thread t;
  TInterrupt()
  {
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
       System.out.println("i plan to sleep for 10 sec");
       //Thread.sleep(10000);//10 sec.
       
       System.out.println("i had a sound sleep");
     }
     catch(InterruptedException ex)
     {
       System.out.println("Somebody interrupted my sleep"); 
     }
    }//if
   }//for
  }//run

  public static void main(String args[])
  {
    TInterrupt ti = new TInterrupt();
    int i;
    for(i =0; i< 1000; i++)
    {
      System.out.print(" M ");
    }
   
    ti.t.interrupt();//transmit interrupt signal to bring ti.t out of sleep
  }
}