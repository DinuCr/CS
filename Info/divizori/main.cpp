#include<iostream>
#include<fstream>
using namespace std;
ifstream f("divizori.in");
ofstream g("divizori.out");
unsigned long long n,m,k,i,ok,gdc,x;
int cmmdc(unsigned long long a,unsigned long long b)
{
  if(a==0)return b;
  return cmmdc(b%a,a);
}
int main()
{
    f>>m>>k;
    gdc=1;
    for(i=k+1;i<m;i++)
    {
        gdc=gdc*i/cmmdc(gdc,i);
    }
    x=gdc;
    while((gdc+k)%m!=0)
        gdc+=x;
    g<<gdc+k;
    g.close();
    return 0;
}
