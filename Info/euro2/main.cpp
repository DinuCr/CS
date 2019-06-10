#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("euro2.in");
ofstream fout("euro2.out");

#define nmax 10100

float v[nmax];
int c[nmax];
int d[nmax];
float q[nmax];
int n,i,p,l;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];

    int st,dr,m;
    float x;
    for(i=1; i<=n; ++i)
    {
        x=v[i];
        st=1;
        dr=l;
        p=0;
        while(st<=dr)
        {
            m=(st+dr)/2;
            if(x<=q[m])
                dr=m-1;
            else
                st=m+1,p=m;
        }
        if(p+1>l)
            ++l;
        q[p+1]=v[i];
        c[i]=p+1;
    }
    l=0;
    for(i=n; i>0; --i)
    {
        x=v[i];
        st=1;
        dr=l;
        p=0;
        while(st<=dr)
        {
            m=(st+dr)/2;
            if(x<=q[m])
                dr=m-1;
            else
                st=m+1,p=m;
        }
        if(p+1>l)
            ++l;
        q[p+1]=v[i];
        d[i]=p+1;
    }
    int mx=0;
    for(i=1; i<=n; ++i)
        if(c[i]>=2 && d[i]>=2)
            mx=max(mx,c[i]+d[i]-1);
    fout<<mx;
}
