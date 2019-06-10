#include<iostream>
#include<fstream>
using namespace std;
ifstream f("culori2.in");
ofstream g("culori2.out");
long long v[6],w[6],i,n,s;
void scandura(long long v[],long long w[])
{
    w[1]=v[2];
    w[2]=v[1]+v[3];
    w[3]=v[2]+v[4];
    w[4]=v[3]+v[5];
    w[5]=v[4];
}
int main()
{
    f>>n;
    for(i=1;i<=5;i++)
        v[i]=1;
    for(i=2;i<=n;i++)
    if(i%2==0)
    scandura(v,w);
    else
    scandura(w,v);
    if(n%2==0)
    for(i=1;i<=5;i++)
        s+=w[i];
    else
    for(i=1;i<=5;i++)
        s+=v[i];
    g<<s;
}
