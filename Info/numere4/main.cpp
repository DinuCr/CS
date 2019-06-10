#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
ifstream f("numere4.in");
ofstream g("numere4.out");
int n,k,p,i,s;
int div(int a)
{
    int x=0,i;
    if(a==1)
        return 1;
    for(i=1;i<=sqrt(a);i++)
        if(a%i==0)
        x+=2;
    return x;
}
int main()
{
    cin>>n>>k>>p;
    for(i=1;i<=n;i++)
    {
        s1=i*(i+1)/2;

    }
}
