/*
Custom Exceptions
------------------
Custom Exceptions are user defined
exceptions, created by defining a
class that extends Exception class.

What does the Custom Exception Class contain?
------------------------------------------
Being a class it can have 
member variables
member methods
constructors
and everything that a class can have.

Plus it is recommended that the
custom exception class overrides

  public String getMessgae(){}
  public String toString(){}
  
Why Custom Exceptions?
---------------------
To deal with logical issues.
Example: Negative input to deposit();
Example: digit found in a name
Example: >n attempts for login
 
When will the custom exception get raised?
---------------------------------------
A custom exception has to be explicitly
raised as some logical issue is traced.

How to raise a custom exception?
-----------------------------
To raise an exception 
1) Create an object of the exception class
2) throw <object>

"throw" statement is used to raise
an exception.
*/

class InputException extends Exception
{
 String msg;

 InputException(String s)
 {
   msg = s;
 } 

 void display()
 {
  System.out.println("InputException : " + msg);
 }

  //recommended overrides
  public String getMessgae()
  {
    return msg;
  }

  public String toString()
  {
    return "InputException : "+ msg;
  }
}//InputException

class Myself
{
 int age;
 String name;

 Myself(String n, int a) throws InputException
 {
  setName(n);
  setAge(a);
 }

 private void setName(String n) throws InputException
 {
  int i;
  char temp;
  for(i =0 ; i< n.length(); i++)
  {
   temp = n.charAt(i);//fetch the current char of name
   if(!((temp >= 65 && temp<= 90) || (temp >= 97 && temp<= 122)))
   {
     //a non alphabet found in name
     //raise an exception
     InputException e = new InputException("Illegal Character "+ temp + " found in name");
     throw e;
   }
  }//for
  name = n;
 }

 private void setAge(int a) throws InputException
 {
  if(a >=0 && a <=100)
   age = a;
  else
  {
   //logically wrong age detected
   //raise an error
   InputException e = new InputException("Age cannot be <0 or >100");
   throw e;
  }
 }//setAge

 void display()
 {
  System.out.println( name +"  " + age);
 }

 public static void main(String args[])
 {
  try
  {
   String q = args[0];
   int w = Integer.parseInt(args[1]);
   Myself m1 = new Myself(q,w);  
   m1.display();
  }
  catch(ArrayIndexOutOfBoundsException e)
  {
   System.out.println("Usage : java Myself <name> <age>");
  }
  catch(NumberFormatException e)
  {
   System.out.println("Usage : java Myself <name> <NUMERIC VALUE>");
  }
  catch(InputException e)
  {
    e.display();
  }
  catch(Exception ex)
  {
   System.out.println(ex);
   //converts into    
   //System.out.println(ex.toString());
  }
 }
}//Myself

/*
Checked and UnChecked Exceptions
-------------------------------
With respect to compilation exceptions
are categorized into
1) Checked Exceptions
2) UnChecked Exceptions

For a checked execption, the compiler
ensures handling.
i.e. It ensures that all possible checked
exceptions are either caught or declared
to be thrown.

For a unchecked execption, the compiler
doesnt raise any issue.
i.e. It wont bother about the handling
or delegation of unchecked exceptions.

------------------------------------


Generic Exception Handler
-------------------------------
Exception class is the generally used
super class for all exceptions in Java.
(Real base class is Throwable).
(See diagram : Throwable Hierarchy).

Known that a super class reference 
can refer to an object of sub class.
So a catch block with Exception class 
reference can handle all the exceptions 
that may arise.
Such a catch block is called as 
"Generic Exception Handler".

Note that for a try, any exception 
can be handled only once.
If a catch with Exception reference 
is defined at the top then it handles 
every possible exception and the 
catch blocks that follow it become 
 "Duplicate handlers".

Hence if defined then a catch block 
with Exception reference must be the
last catch among the set of catch blocks 
associated with a try block. 

In such cases the preceeding catch
blocks handle respective exceptions 
and the last generic catch block 
handles rest of the unseen exceptions.
*/