#include<iostream>
#include<cmath>
using namespace std;
int isprime(int num)
{   int i=1;
    if(num==1)
    {cout<<"neither prime nor composite"<<endl;
    return 0;}
    else if(num==2)
    {cout<<"prime"<<endl;
    return 0;}
    else
    {for(i=2;i<=sqrt(num);i++)
    {if(num%i==0)
    {cout<<"not prime"<<endl;
    return 0;}
    }
    cout<<"prime"<<endl;
     return 0;}
    }
int main()
{int n;
cout<<"enter a number"<<endl;
cin>>n;
isprime(n);}