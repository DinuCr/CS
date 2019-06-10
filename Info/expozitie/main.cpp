#include<iostream>
#include<fstream>
using namespace std;
ifstream f("expozitie.in");
ofstream g("expozitie.out");
long long n,d,k,s,i,v[1000],j,t;
int main()
{
    f>>n>>d>>k;
    s=d;
    while(s)
    {
        i++;
        v[i]=s%10;
        s/=10;
    }
    v[0]=i;
    for(i=2;i<=n-d*k;i++)
    {
        t=0;
        for(j=1;j<=v[0];j++)
        {
            t+=v[j]*d;
            v[j]=t%10;
            t/=10;
        }
        while(t)
        {
            v[0]++;
            v[v[0]]=t%10;
            t/=10;
        }
    }
    for(i=v[0];i>0;i--)
        g<<v[i];
}
