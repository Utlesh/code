/*
File Read
----------
* open the file
* until EOF
    fetch data
    display data
* close the file


*/

import java.io.*;

class FRead
{
 public static void main(String args[])
 {
  try
  {
   String fname = args[0];
 
   //open the file
   FileInputStream fin = new FileInputStream(fname);//either opens the file or raised FileNotFoundException
 
   //fetch data byte by byte
   int data, cnt;  
   cnt = 0;

   while( (data = fin.read()) != -1)
   {
    System.out.write(data);
    cnt++;
   }
   System.out.flush();

   //close the file
   fin.close();

   System.out.println("\n File read in " + cnt + " cycles");
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage : java FRead <filename>");
  }
  catch(IOException ex)
  {
   System.out.println(ex);
  }

 }//main
}