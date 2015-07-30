class A
{
 final void f1()
 {
  System.out.println("A final method cannot be overridden");
 }
}//A

class B extends A
{
 /*void f1()
 {
  System.out.println("B f1()");
 }*/
}

class FMethod
{
 public static void main(String args[])
 {
  B obj = new B();
  obj.f1();
 }
}//FMethod