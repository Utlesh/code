class NThreads extends Thread
{
 int flag;

 NThreads(int x)
 {
   flag = x;
   start();//activate the thread
 }

 public void run()
 {
   System.out.println("run starts");

   if(flag ==1)
    f1();
   else if(flag == 2)
    f2();

   System.out.println("run ends");
 }

 void f1()
 {
  int i;
  for(i =0; i< 500; i++)
   System.out.print(" 1 "); 
 }

 void f2()
 {
  int i;
  for(i =0; i< 500; i++)
   System.out.print(" 2 "); 
 }

 public static void main(String args[])
 {
   NThreads nt1 = new NThreads(1);//a user defined thread
   NThreads nt2 = new NThreads(2);//a user defined thread
  int i;
  for(i =0; i< 500; i++)
   System.out.print(" 3 ");
 }//main
}