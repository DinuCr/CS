#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("petrecere.in");
ofstream fout("petrecere.out");

int a[4000];
int b[4000];
int c[4000];
int d[4000];
int i,n;

void cpy(int a[],int b[])
{
    a[0]=b[0];
    for(int i = 1; i<=a[0]; ++i)
        a[i]=b[i];
}

void multiply(int a[],int x)
{
    int t = 0;
    for(int i=1; i<=a[0]; ++i)
    {
        t+=a[i]*x;
        a[i]=t%10;
        t/=10;
    }
    while(t)
    {
        ++a[0];
        a[a[0]]=t%10;
        t/=10;
    }
}

void add(int c[],int a[],int b[])
{
    int t = 0;
    int siz=max(a[0],b[0]);
    c[0]=siz;
    for(int i=1; i<=siz; ++i)
    {
        t+=a[i]+b[i];
        c[i]=t%10;
        t/=10;
    }
    while(t)
    {
        ++c[0];
        c[c[0]]=t%10;
        t/=10;
    }
}

int main()
{
    fin>>n;
    a[0]=1;
    a[1]=1;
    b[0]=1;
    b[1]=2;
    if(n==1)
        fout<<1;
    else
    if(n==2)
        fout<<2;
    else
    {
        for(i=3; i<=n; ++i)
        {
            cpy(d,a);
            multiply(d,i-1);
            add(c,b,d);
            cpy(a,b);
            cpy(b,c);
        }
        for(i=c[0]; i>0; --i)
            fout<<c[i];
    }
}
