class Time
{
 //member variables
 int h, m, s;

 //member methods
 void setTime(int a, int b, int c) //void setTime(Time this, int a, int b, int c) 
 {
   int s;
   h = a;//this.h = a;
   m = b;//this.m = b;
   s = c;//s = c; (shadowing)
   this.s = c; //(soln to shadowing)
 }
 
 void displayTime()
 {
  System.out.println(h + ":" + m + ":" + s);
 }

 void incrementTime()
 {
   h++;
   m++;
   s++;
 }

 public static void main(String args[])
 {
  //define object of Time
  Time t = new Time();
  Time t1 = new Time();

  t.setTime(1,2,3); //setTime(t,1,2,3);
  t1.setTime(10,20,30);
  t1.incrementTime();

  t.displayTime(); 
  t1.displayTime();
 }

}//Time