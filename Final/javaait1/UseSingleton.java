/*
Singleton class

A singleton class is a class that
can be instantaited only once.
i.e. Its only one object may be
created.

To design a singleton class
* Hide all of its constructors.
* Define a public static method
that creates one object of the
class and returns the same everytime.
*/

class Singleton
{
 int x, y;
 private static Singleton ref;
 
 static
 {
  System.out.println("in static block of Singleton");
  ref = null;
 }
 
 private Singleton()
 {
  System.out.println("Singleton()");
  x = 10;
  y = 20;
 }

 void increment()
 {
  x++;
  y++;
 }
 
 void display()
 {
  System.out.println(x + " " + y);
 }


 public static Singleton getObject()
 {
  System.out.println("in getObject()");
  if(ref == null)
    ref = new Singleton();

  return ref;
 }
}//Singleton


class UseSingleton
{
 public static void main(String args[])
 {
  System.out.println("=============");
  Singleton s1= Singleton.getObject();
  System.out.println("=============");
  Singleton s2 = Singleton.getObject();
  System.out.println("=============");

  s1.display();
  s2.display();

  s2.increment();

  s1.display();
  s2.display();

  if(s1 == s2)
  {
   System.out.println("Both references refer to the same object");
  }

 }//main
}