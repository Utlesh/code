#include<iostream>
using namespace std;

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

int main()
{
 node p1,p2,q1,q2;
 cin>>p1.x>>p1.y;
 cin>>p2.x>>p2.y;
 cin>>q1.x>>q1.y;
 cin>>q2.x>>q2.y;
 doIntersect(p1,p2,q1,q2) ? cout<<"Lines Intersects\n":cout<<"Lines doesn't Intersects\n";
 return 0;
}
