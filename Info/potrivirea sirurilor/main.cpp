#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
using namespace std;
ifstream f("strmatch.in");
ofstream g("strmatch.out");
int v[2000100],p[2000100],n,m,i,k,nr;
char a[2000100],b[2000100];
void phi()
{
    int i,k;
    p[1]=0;
    for(i=2;i<=n;i++)
    {
        k=p[i-1];
        while(k>0 && a[i]!=a[k+1])
            k=p[k];
        if(a[i]==a[k+1])
            p[i]=k+1;
    }
}
int main()
{
    fgets(a,2000100,f);
    for(i=strlen(a);i>0;i--)
        a[i]=a[i-1];
    f.getline(b,2000100);
    for(i=strlen(b);i>0;i--)
        b[i]=b[i-1];
    m=strlen(b)-1;
    n=strlen(a)-1;
    a[0]=NULL;
    b[0]=NULL;
    a[n+1]=' ';
    phi();
    for(i=1;i<=m;i++)
    {
        k=v[i-1];
        while(k>0 && b[i]!=a[k+1])
            k=p[k];
        if(b[i]==a[k+1])
            v[i]=k+1;
    }
    for(i=1;i<=m;i++)
        if(v[i]==n)
        nr++;
    g<<nr<<'\n';
    if(nr>1000)
        nr=1000;
    for(i=1;nr>0 && i<=m;i++)
        if(v[i]==n)
            g<<i-n<<' ',nr--;
}
