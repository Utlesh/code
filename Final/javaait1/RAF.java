/*
Study of RandomAccessFile

RandomAccessFile object is used to
* open a file in read-write mode
* perform seek.
* read/write java datatypes.

*/
import java.io.*;

class RAF
{
 public static void main(String args[])
 {
  try
  {
   String fname = "d:\\q.txt";
   String mode ;
   //mode = "r";//r : file must exist
   mode = "rw";//rw : file will be created or opened

   //open the file
   RandomAccessFile raf = new RandomAccessFile(fname, mode);

/*
//seek and write demo

   raf.seek(10);//position file r/w pointer at index 10 wrt BOF
   //a seek beyond file size causes file to grow upto the seek value  
   raf.write(65);//raf.write('A');

*/   

//r/w java datatypes
   int i1, i2;
   float f1,f2;
   char c1,c2;
   String s1, s2;

   i1 = -10;
   f1 = 1234.5678F;
   c1 = 'q';
   s1 = "hello files";

   raf.seek(0); //reach BOF
   raf.writeInt(i1);
   raf.writeFloat(f1);
   raf.writeChar(c1);
   raf.writeUTF(s1);
 

   raf.seek(0);//reach BOF
   i2 = raf.readInt();
   f2 = raf.readFloat();
   c2 = raf.readChar();
   s2 = raf.readUTF();

   System.out.println(i2);
   System.out.println(f2);
   System.out.println(c2);
   System.out.println(s2);

   //close the file
   raf.close();
  }  
  catch(IOException ex)
  {
   System.out.println(ex);//ex converts into ex.toString()
  }
 }//main
}//RAF

