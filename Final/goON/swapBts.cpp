#include<iostream>
using namespace std;

int main()
{
	int num1,res,ind,tmp2,tmp1,x,cnt,p1,p2,Exor;
	cout<<"Enter number:\n";
	cin>>num1;
	cout<<"Enter two position's :\n";
	cin>>p1>>p2;
    cout<<"How many bit's to be swapped:\n";
    cin>>cnt;

    x = (1<<cnt)-1;
    tmp1 = num1>>p1;
    tmp2 = num1>>p2;
    tmp1 = tmp1&x;
    tmp2 = tmp2&x;
    Exor = tmp1^tmp2;
    cout<<tmp1<<" "<<tmp2<<"\n";
    
    res = (Exor<<p1 | Exor<<p2)^num1;
    cout<<res<<"\n";

    return 0;
}