class Mythread extends Thread
{
 public void run()
  {
   for(int i=0;i<500;++i)
    System.out.print('-');
  }

 public static void main(String args[])
  {
   Mythread thrd = new Mythread();
   thrd.start();
   
   System.out.println("No. of active thread is:"+" "+Thread.activeCount());
   for(int i=0;i<500;++i)
    System.out.print('|');
  }
}


 
