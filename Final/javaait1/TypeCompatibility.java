/*
Type Compatibility

Inheritance creates type compatiblity
between the super and the sub
classes.
It allows a super class reference
to refer to an object of the
sub class.
Reverse is not true.

A super class reference that
refer's to a sub class object
can be used to access only
those members that originate
from the super class.
The members that are newly
defined by the sub class, are
not accessible. 

*/


class A
{
 void f1()
 {
   System.out.println("A f1()");
 }
 void f2()//overridden method
 {
   System.out.println("A f2()");
 }
}//A


class B extends A
{
 void f2()//overriding method
 {
   System.out.println("B f2() starts");
   f3();
   System.out.println("B f2() ends");
 } 

 void f3()
 {
   System.out.println("B f3() starts ");
   super.f2();//access f2() of parent class
   System.out.println("B f3() ends ");

 } 
 
}//B

class TypeCompatibility
{
 public static void main(String args[])
 {
   if(args.length == 0)
   {
    System.out.println("usage : java TypeCompatibility A");
    System.out.println("usage : java TypeCompatibility B");
    return; //terminate main
   }

   A refA = null;
 

   if(args[0].equals("A"))
    refA = new A();//self type
   else if(args[0].equals("B"))
    refA = new B();//type compatibility
   else
   {
    System.out.println("usage : java TypeCompatibility A");
    System.out.println("usage : java TypeCompatibility B");
    return; //terminate main
   }
  
   //refA.f1();//inherited method
   refA.f2();//overridden method
   
 }//main
}//TypeCompatibility
/*
---------------------------------
super
------
"super" can be used in non static methods
of a sub class to refer to the super class.

It is used :
* to access overridden methods of super class
* to access hidden member variables of super class 
* to invoke the desired constructor of super class



*/