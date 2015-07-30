/*
Exception Handling
-----------------
Exceptions are runtime errors that
cause abnormal program termination.

Aim : To develope robust applications
that donot terminate abnormally.

Need : To protect the application from
run time errors (exceptions) and hence
avoid abnormal termination. 

Implementation
-------------
To protect an application from exceptions
it must use Java's exception handling
mechanism.
(try-catch-finally-throws and throw).

try
----
A try block contains code that may 
cause exceptions.
System monitors the code that is 
inside the try block, for exceptions.
As an exception occurs in try block,
system doesnt cause abnormal program
termination but 
1) Interrupts the normal program execution.
2) Transfers the program control into a corresponding catch block.

If for an exception that has occurred
in try block, there is no corresponding
catch block, then it will cause abnormal
program termination.

catch
------
A catch block is an exception handler
block.
If for an exception that occurs in try
block, there is a catch block then 
it (catch) executes and cancels the 
abnormal program termination.
 
If there is no execption corresponding
to a catch then the code of catch wont
execute. 

finally
-------
A finally block follows try or the
last catch block (if defined).

It is invoked by the system irrespective
of execption occurrence and irrespective
of its handling.

Generally it contains resource cleanup
code.
*/

class EDemo1
{
 public static void main(String args[])
 {
  try
  {
   int a,b,c;
   a = Integer.parseInt(args[0]);//val comes from args[0]
   b = Integer.parseInt(args[1]);//val comes from args[1]
   c = a/b;
   System.out.println("a : " + a);
   System.out.println("b : " + b);
   System.out.println("c : " + c);
  }
  catch(NumberFormatException e)
  {
    System.out.println("Invalid Data"); 
  }
  catch(ArrayIndexOutOfBoundsException e)
  {
    System.out.println("Insufficient Data");
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
}//EDemo1


/*
Integer.parseInt()
----------------
parseInt() is a static method of class
Integer.

It accepts a string and converts the
same into an int value.

If conversion succeeds then int value
is returned.
But if conversion fails then it raises
NumberFormatException.

------------------------------------
If an array is used beyond its size
then the usage causes ArrayIndexOutOfBoundsException.

------------------------------------
If a whole number is divided by ZERO
then it is a cause of ArithmeticException

*/