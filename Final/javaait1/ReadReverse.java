/*
Read a file in reverse
*/

import java.io.*;

class ReadReverse
{
 public static void main(String args[])
 {
  try
  {
   String fname = args[0];
   String mode = "r";//r : file must exist
  
   //open the file
   RandomAccessFile raf = new RandomAccessFile(fname, mode);

   long len = raf.length();//file size in bytes
   long i;
   int data;

   for(i = len-1; i>=0; i--)
   {
    raf.seek(i);//position file pointer at index i
    data = raf.read();
    System.out.write(data);
   }
 
   System.out.flush();
  

   //close the file
   raf.close();
  }  
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage : java ReadReverse <filename>");
  }
  catch(IOException ex)
  {
   System.out.println(ex);//ex converts into ex.toString()
  }
 }//main
}//ReadReverse
