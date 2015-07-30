/*
Inheritance

Inheritance is a mechanism by
which a class (entity) gets code
(operations) and data (characteristics)
from an existing class (entity).


In Java "extends" keyword is 
used to apply inheritance of
classes/interfaces.

The inheriting class/interface
is called as the "sub class" or
"sub interface".

The inherited class/interface
is called as the "super class"
or "super interface".
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
   System.out.println("B f2()");
 } 

 void f3()
 {
   System.out.println("B f3()");
 } 
 
}//B


class InheritCode
{
 public static void main(String args[])
 {
  B objB= new B();
  objB.f1();//inherited method
  objB.f2();//inherited method
  objB.f3();//new method of sub class
 }//main
}//InheritCode

/*
Method overriding
Is redefining a super class
non static method in the sub
class, keeping the methods
signature exactly same.

*/