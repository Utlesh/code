#include<iostream>
using namespace std;
#include<stdio.h>

#define INF 10000
struct node{
 int x,y;
};

bool onSegment(node p1,node p2,node p3)
{
 if(min(p1.x,p3.x)<p2.x&&max(p1.x,p3.x)>p2.x&&min(p1.y,p3.y)<p2.y&&max(p1.x,p3.x)>p2.y)
   return true;
 return false;
}

int orientation(node p1,node p2,node p3)
{
  int a = (p2.y-p1.y)*(p3.x-p2.x) - (p3.y-p2.y)*(p2.x-p1.x);
  if(a==0)
    return a;
  return (a>0)?1:2 ;
   
}

bool doIntersect(node p1,node p2,node q1,node q2)
{
 int o1 = orientation(p1,p2,q1);
 int o2 = orientation(p1,p2,q2);
 int o3 = orientation(q1,q2,p1);
 int o4 = orientation(q1,q2,p2);

 if(o1!=o2&&o3!=o4)
  return true;
 
 if(o1==0&&onSegment(p1,q1,p2))
   return true;

 if(o2==0&&onSegment(p1,q2,p2))
   return true;

 if(o3==0&&onSegment(q1,p1,q2))
   return true;

 if(o4==0&&onSegment(q1,p2,q2))
   return true;
  
 return false;
}

bool polygon(node poly[],int n,node pnt)
{
 if(n<3)
  return false;

 int count=0,i=0;
 node x = {INF,pnt.y};
 do
  {
    int nxt = (i+1)%n;  
    if(doIntersect(poly[i],poly[nxt],x,pnt))
      {
       if(orientation(poly[i],pnt,poly[nxt])==0)
         return onSegment(poly[i],pnt,poly[nxt]);
        ++count;
      }
    i = nxt;
  }while(i!=0);

 return count&1;
}

int main()
{
 node polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    int n = sizeof(polygon1)/sizeof(polygon1[0]);
    node p = {20, 20};
    polygon(polygon1, n, p)? cout << "Yes \n": cout << "No \n";
 
    p = {5, 5};
    polygon(polygon1, n, p)? cout << "Yes \n": cout << "No \n";
 
    node polygon2[] = {{0, 0}, {5, 5}, {5, 0}};
    p = {3, 3};
    n = sizeof(polygon2)/sizeof(polygon2[0]);
    polygon(polygon2, n, p)? cout << "Yes \n": cout << "No \n";
 
    p = {5, 1};
    polygon(polygon2, n, p)? cout << "Yes \n": cout << "No \n";
 
    p = {8, 1};
    polygon(polygon2, n, p)? cout << "Yes \n": cout << "No \n";
 
    node polygon3[] =  {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    p = {-1,10};
    n = sizeof(polygon3)/sizeof(polygon3[0]);
    polygon(polygon3, n, p)? cout << "Yes \n": cout << "No \n";
 
    return 0;
}
