//Inheritance of Static Methods

class HasMain
{
 static void f()
 {
  System.out.println("f() of  HasMain");
 }

 public static void main(String args[])
 {
  System.out.println("Main of HasMain");
  f();//HasMain.f();
 }
}//HasMain


class InheritsMain extends HasMain
{}


/*
static methods (if not private) of
a super class are directly accessible
to the sub class.
This includes the main method also.

The sub class is also allowed to
redefine a static method as already
defined by the super class.

*/