#include <iostream>
#include <fstream>
using namespace std;
ifstream f("scmax.in");
ofstream g("scmax.out");
int a[100010],d[100010],v[100010],n,i,j,p,mx,st,dr,x,m,l;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(i=1;i<=n;i++)
    {
        x=v[i];
        st=1;
        dr=l;
        p=0;
        while(st<=dr)
        {
            m=(st+dr)/2;
            if(x<=a[m])
                dr=m-1;
            else
                st=m+1,p=m;
        }
        if(p+1>l)
            a[++l]=x;
        a[p+1]=x;
        d[i]=p+1;
    }
    mx=0;
    for(i=1;i<=n;i++)
        if(d[i]>mx)
        {
            p=i;
            mx=d[i];
        }
    l=0;
    while(d[p]!=0)
    {
        a[++l]=v[p];
        for(i=p;i>0;i--)
            if(v[i]<v[p] && d[i]==d[p]-1)
            break;
        p=i;
    }
    g<<l<<'\n';
    for(i=l;i>0;i--)
        g<<a[i]<<' ';
}
