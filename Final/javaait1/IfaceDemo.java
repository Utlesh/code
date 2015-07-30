/*
Interface
----------
An interface is a collection of
 * static and final data members 
 * abstract methods
 * nested classes
 * nested interfaces

An interface declares a new 
"reference type" in Java,
i.e. a type that cannot be instantiated.

--------------------------------
Access Specifiers for an interface

All the interface members are
"public" by default.
They can be explictly declared as 
"public", but not as "private" or 
"protected".

Inheritanc of Interfaces
------------------------
Java allows an interface to inherit
one to many unique interfaces.
An interface cannot inherit any class.


How to use an interaface
-----------------------
An interface is implemented by some
class and used. 

If a class implements an interface
then it 
* must the override all the abstract methods of all the implemented interfaces
* becomes type compatible with the interface reference.


*/



interface Iface1
{
 int q= 10;//public, static and final by default. It must be initialized along with declaration
 void f1();//public and abstract by default
}

interface Iface2
{
 void f2();
}

interface CIface extends Iface1, Iface2
{
 void f3();
}

class UseIface implements CIface
{
 public void f1()
 {
   System.out.println("UseIface f1");
 }
 public void f2()
 {
   System.out.println("UseIface f2");
 }
 public void f3()
 {
   System.out.println("UseIface f3");
 }
 void f4()
 {
   System.out.println("UseIface f4");
 }
}


class IfaceDemo
{
public static void main(String args[])
{
 Iface1 r1 = new UseIface();
 Iface2 r2 = new UseIface();
 CIface r3 = new UseIface();
 UseIface r4 = new UseIface();

 System.out.println("===============");
 r1.f1();
 //r1.f2();
 //r1.f3();
 //r1.f4();  
 System.out.println("===============");
 //r2.f1();
 r2.f2();
 //r2.f3();
 //r2.f4();  
 System.out.println("===============");
 r3.f1();
 r3.f2();
 r3.f3();
 //r4.f4();  
 System.out.println("===============");
 r4.f1();
 r4.f2();
 r4.f3();
 r4.f4();  
 System.out.println("===============");

 
}
}


