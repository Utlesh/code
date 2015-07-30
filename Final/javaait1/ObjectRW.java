//read/write objects 
import java.io.*;

class Student implements Serializable
{
 int rno;
 String name;
 /*transient*/ double percentage;

//transient fields are not serialized
 Student()
 {
  rno = 10;
  name = "vikas";
  percentage = 65;
 }

 Student(int r, String n, double p)
 {
  rno = r;
  name = n;
  percentage = p;
 }

 void display() 
 {
  System.out.println("rno : " + rno);
  System.out.println("name : " + name);
  System.out.println("percentage : " + percentage);
 }

}//Student

class ObjectRW
{
 public static void main(String args[])
 {
 try
 {

  //--------write object---------

  //open a file for writing
  FileOutputStream fout = new FileOutputStream("myObjects.txt");

  //create ObjectOutputStream for object serialization and writing
  ObjectOutputStream oos = new ObjectOutputStream(fout);  

  //Create objects
  Student s1 = new Student();
  Student s2 = new Student(20, "anil", 66);

  //serialize
  oos.writeObject(s1);
  oos.writeObject(s2);
  
  //close the file
  oos.flush();
  oos.close();
  fout.close();

  //--------- object fetch----------
    
  //open a file for reading
  FileInputStream fin = new FileInputStream("myObjects.txt");

  //create ObjectInputStream for object reading and deserialization
  ObjectInputStream ois = new ObjectInputStream(fin);  

  //Fetch objects
  Student s3, s4;
  s3 = (Student) ois.readObject();
  s4 = (Student) ois.readObject();
  
  s3.display();
  s4.display(); 

  if(s1.equals(s3) || s2.equals(s4))
   System.out.println("SAME");
  else
   System.out.println("DIFFERENT");

 }
 catch(Exception ex)
 {}
 }//main
}//ObjectRW

/*
Java supports reading/writing of
objects from/in files.

For this the class of the object must
implement the Serializable interface.
The interface is empty but is required
for type compatibility with Java API.
 
Next for writing the objects in a file
one must use ObjectOutputStream.

And for reading the objects from a 
file one must use ObjectInputStream.
*/