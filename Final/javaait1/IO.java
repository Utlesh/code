/*
Stream
-------
A stream is a software entity that
allows transfer of information between
applications/devices.

A stream may be unidirectional or
bidirectional and hence will accordingly
allow data transfer.

Operations on stream
--------------------
A stream must be
1) opened
2) read/written
3) closed

A stream may be opened in
text mode or in binary mode.

A stream opened in text mode allows
transfer of ASCII values in range
0-255 only.

A stream opened in binary mode allows
transfer of all ASCII values.

There are 3 standard streams that 
are managed by the OS and are made
available to the active application.
They are :

1) Standard Input Stream
It is the stream that connects keyboard
and the application.
It is represented by public static final
object System.in
It is a binary stream of type java.io.InputStream.


2) Standard Output Stream
It is the stream that connects java
application and the monitor.
It is represented by public static final
object System.out
It is a binary stream of type java.io.PrintStream.

3) Standard Error Stream
It is the stream that connects java
application and the monitor.
It is represented by public static final
object System.err
It is a binary stream of type java.io.PrintStream.

Important Functions of class PrintStream
------------------------------------

write(int)
--------
Accepts an ASCII value and writes it
into the stream.

write(byte[], int fromI, int toI)
----------------------------
Accepts a byte array filled with ASCII 
values and writes its content in range fromI
to toI into the stream.
fromI : inclusive
toI : exclusive

print()
-------
To output values stored in variables
of primary datatypes.
Is overloaded to handle all the data
types.

println()
--------
To output values stored in variables
of primary datatypes PLUS a newline.
Is overloaded to handle all the data
types.

printf()
-------
C like printf()

flush()
-------
Force transmit the buffered data into
the stream.

Important functions of class java.io.InputSteam
-------------------------------------------

int read()
---------
Fetches one byte of data from the stream.
Returns its ASCII value.
Returns -1 if fetch encounters EOF/EOS.
Blocks execution until data is fetched.
throws IOException.

int read(byte[])
--------------
Fetches n bytes of data from the stream.
Where 
n = length of array
or
n = number of bytes available in the stream
Whichever is less.
Puts the fetched data into the array.
Returns n.
Returns -1 if fetch encounters EOF/EOS.
Blocks execution until data is fetched.
throws IOException.


int available()
-------------
returns the number of bytes available
in the input stream.

skip(long)
---------
skips i.e. advances the fetch pointer
ahead by specified amount.


*/

import java.io.IOException;

class IO
{
 static String getString()
 {
  String temp = "";
  int data;
  try
  {
   do
   {
    data = System.in.read();
    temp = temp + (char) data;
   }while(System.in.available() > 2);

   //2 are the last 2 bytes of enter (13,10)
   //clear the input stream
   System.in.skip(2);
  }
  catch(IOException ex)
  {} 
  return temp;  
 }

 static String getString1()
 {
  int n;
  byte data[] = new byte[100];
  try
  {
    n = System.in.read(data);
    String temp = new String(data, 0, n-2);
    return temp;
   //2 are the last 2 bytes of enter (13,10)
  }
  catch(IOException ex)
  {} 
  return "";  
 }

 static void writeDemo()
 {
   int x = 65;
   System.out.write(x);
   System.out.flush();
 }

 static void writeDemo1()
 {
   byte arr[] = {65,66,67,68,69};
   System.out.write(arr, 0, 5);
   System.out.flush();
 }

 static void printDemo()
 {
   int x = 65;
   System.out.print(x);
 }

 static void printlnDemo()
 {
  System.out.println("Hello");
  System.err.println("Streams");
 }

 static void printfDemo()
 {
  char q= 'a';
  int w = -19;
  float e = 2.345F;

  //System.out.printf("\n %c %d", q,w);
  //System.out.printf(" %f ", e);
  //same as above
  System.out.printf("\n %c %d", q,w).printf(" %f ", e);

 }

 public static void main(String args[])
 {
  //writeDemo();
  //writeDemo1();
  //printDemo();
  //printlnDemo();
  //printfDemo();
  
  String s;
  System.out.println("Enter a string ");
  //s = getString();
  s = getString1();

  System.out.println("String : " + s);


 }
}