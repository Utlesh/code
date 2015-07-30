/*
Thread Sleep

Thread sleep ceases execution of the
current thread for a specific period.

The accuraccy of sleep depends on
systems timers and schedulers.

Thread sleep throws InterruptedException
which the caller must handle.


*/

class TSleep extends Thread
{
 TSleep()
 {
  start();
 }

 public void run()//thread life cycle method
 {
   int i;
   for(i =0 ; i< 20; i++)
   {
     System.out.println(" T " + System.currentTimeMillis());
      try
      {  
        Thread.sleep(1000);//a delay of 1 sec (1000 milli sec.)
      }
      catch(InterruptedException ex)
      {}
   }//for

 }//run

 public static void main(String args[])
 {
   TSleep ts = new TSleep();
 }//main
}