/*
Java allows a method to redirect 
(transfer/delegate) an exception
instead of handling it.
In such a case the handling of the
exception is to be done by the caller
of the method.

"throws" statement is used by methods
to transfer an unhandled exception
on caller of the method. 
The caller must handle it or further
declare the same to be thrown.

*/
class EDemo2
{
 int a,b,c;

 void set(String arr[]) throws NumberFormatException , ArrayIndexOutOfBoundsException
 {
   a = Integer.parseInt(arr[0]);
   b = Integer.parseInt(arr[1]);
 }

 void process() throws ArithmeticException
 {
  c = a/b;
 }

 void display()
 {
   System.out.println("a : " + a);
   System.out.println("b : " + b);
   System.out.println("c : " + c);
 }

 public static void main(String args[])
 {
  try
  {
   EDemo2 ed2 = new EDemo2();

   try
   {
    ed2.set(args);
   }
   catch(ArrayIndexOutOfBoundsException e)
   {
    System.out.println("Insufficient User Input, Using Default values 10,2");
    ed2.a = 10;
    ed2.b = 2;
   }
   
   ed2.process();
   ed2.display();

  }
  catch(NumberFormatException e)
  {
    System.out.println("Invalid Data"); 
  }
  catch(ArithmeticException e)
  {
    System.out.println("Infinity");
  }
  finally
  {
    System.out.println("IN FINALLY");
  } 
  System.out.println("main ends");
  
 }//main
}//EDemo2

