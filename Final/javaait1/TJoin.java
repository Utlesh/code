/*
Thread Join

Thread join causes suspension of the
current thread 
* until the target thread is complete.
* for a specific time.

If the target thread is already complete
then the current thread suspends and
immediately comes out of suspension
(effectively equal to no suspension).

Thread join throws InterruptedException
which the caller must handle.

Improper use of join() may cause system
deadlock.
In such a case one must use
* Interrupt Signals
* timed join :  th.join(millis);

*/

class TJoin extends Thread
{
 TJoin()
 {
  start();
 }

 public void run()//thread life cycle method
 {
   System.out.println("\n run starts ");

   int i;
   for(i =0 ; i< 500; i++)
     System.out.print(" T ");

   System.out.println("\n run ends ");

 }

 public static void main(String args[])
 {
   System.out.println("\n main starts ");

   TJoin tj = new TJoin();


   int i;
   for(i =0 ; i< 500; i++)
   {
     System.out.print(" M ");
     if(i == 100)
     {
      System.out.println("\n main about to call join ");
      try
      {  
        System.out.println("tj is alive : " + tj.isAlive());
        tj.join();//infinite suspension or suspension until thread tj completes
        System.out.println("tj is alive : "  + tj.isAlive());
      }
      catch(InterruptedException ex)
      {}
      System.out.println("\n main out of join ");       
     }
  
   }//for

   System.out.println("\n main ends ");


 }//main
}