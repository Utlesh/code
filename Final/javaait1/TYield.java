/*
Thread Yield
------------
Yield is used by a thread to voluntarily 
give up execution of current CPU cycle
and let other threads utilize CPU time.

This is a way to implement co-operative
multi-threading.
 
*/
class TYield extends Thread
{

 TYield()
 {
   start();//activate it
 } 

 public void run()
 {
  int i;
  for(i =0 ; i< 20; i++)
  {
   System.out.print("|");
   Thread.yield();
  }
 }
  
 public static void main(String args[])
 {
  TYield ty =  new TYield();

  
  int i;
  for(i =0; i< 20; i++)
  {
   System.out.print("-");
   Thread.yield();
  }

 }//main
}
