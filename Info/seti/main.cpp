#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
char a[200100],b[200100];
int p[200100],v[200100],i,n,m,k,nr,x[200100],t,w[200100];
ifstream f("seti.in");
ofstream g("seti.out");
void phi()
{
    int i,k;
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
    f.getline(b,200100);
    for(i=strlen(b);i>0;i--)
        b[i]=b[i-1];
    i=1;
    while(f>>a[i])
    {
        if(a[i]=='?')
        i--,x[++t]=i;
        i++;
    }
    a[i]=NULL;
    a[0]=1;
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
        w[v[i]]++;
    for(i=n;i>0;i--)
        w[p[i]]+=w[i];
    for(i=1;i<=t;i++)
        g<<w[x[i]]<<'\n';
}
