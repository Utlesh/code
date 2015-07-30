/*
File Copy
----------
* open source and target files
* until End Of Source File
    fetch data from source file
    write data in target file
* close both the files


*/

import java.io.*;

class FCopy2
{
 public static void main(String args[])
 {
  try
  {
   String sfname = args[0];
   String tfname = args[1];
 
   //open the source file in binary mode for reading
   FileInputStream fin = new FileInputStream(sfname);//for open to suceed, the file must exist
   //open the target file in binary mode for writing
   FileOutputStream fout = new FileOutputStream(tfname);//file will be created/overwritten
 
   //fetch data byte by byte
   int n, cnt;  
   byte arr[] = new byte[512];
   cnt = 0;

   while( (n = fin.read(arr)) != -1)
   {
    fout.write(arr, 0, n);
    cnt++;
   }
   fout.flush();

   //close the files
   fin.close();
   fout.close();

   System.out.println("\n File copied in " + cnt + " cycles");
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage : java FCopy2 <srcfilename> <trgtfilename>");
  }
  catch(IOException ex)
  {
   System.out.println(ex);
  }

 }//main
}