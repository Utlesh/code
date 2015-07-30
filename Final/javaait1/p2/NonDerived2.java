package p2;

import p1.Base;
public class NonDerived2  
{
 //attempt to access members of 
 //another class of same package

 Base ref;

 public NonDerived2()
 {
  System.out.println("p2 NonDerived2 NonDerived2()");
  ref = new Base();
  //ref.i++;
  //ref.j++;
  //ref.k++;
  ref.l++;
 }
 
 public void display() 
 {
  System.out.println("p2 NonDerived2 display()");
  System.out.println("ref.i : not accessible ");
  System.out.println("ref.j : not accessible");
  System.out.println("ref.k : not accessible");
  System.out.println("ref.l : "+ ref.l);
  System.out.println("=============");
  ref.display(); 

 }
}//NonDerived2