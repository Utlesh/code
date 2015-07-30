/*
Thread Priority
---------------
Thread Priority decides which of the
multiple threads get access of the
resource first.

The O/S CPU scheduling queue, being
a priority queue gives frequent access
of the CPU time to high priority threads.

This causes starvation of low priority
threads.

Hence, generally said, the idea of
changing threads priority is against
the idea of co-operative multitasking.

Setting Thread Priority
---------------------
Priority of a thread can be set using
the setPriority(int) method.
The parameter to the method is an
int value that represents threads
priority.
It is a value in range 1-10.
1 being the least priority.
5 the normal priority (default).
10 the maximum priority.

Setting a value beyond the range (1-10)
causes IllegalArgumentException.

Getting Thread Priority
---------------------
The priority of a thread can be fetched
using the getPriority() method. It returns
an int value the represents threads priority.

*/

class TPrior implements Runnable
{
 Thread t;

 TPrior(int p)
 {
  t = new Thread(this);
  t.setPriority(p);
  t.start();
 }

 public void run()
 {
  int i;
  for(i =0; i< 1000; i++)
   System.out.print(" T ");
 }

 public static void main(String args[])
 {
  TPrior tp = new TPrior(8);//priority higher than normal

  Thread mt = Thread.currentThread();
  mt.setPriority(3);//priority less then normal

  int i;
  for(i =0 ; i< 1000; i++)
   System.out.print(" M ");

 }//main
}//TPrior