#include <iostream>
#include <algorithm>

using namespace std;
#define nmax 2100

int v[nmax];
int w[nmax];
int fr[nmax];
int c[nmax];
int k,m,n,i,nr,mn;

int prim()
{
    for(int i=1; i<=m; ++i)
        if(fr[i]<mn)
        {
            return i;
        }
    return 0;
}
int main()
{
    cin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
    }

    mn=n/m;
    cout<<mn<<' ';
    for(i=1; i<=n; ++i)
        if(v[i]<=m)
            fr[v[i]]++;

    for(i=1; i<=n && prim()!=0; ++i)
    {
        if(v[i]<=m)
        {
            if(fr[v[i]]>mn && prim()!=0)
                ++nr,fr[v[i]]--,v[i]=prim(),fr[v[i]]++;
        }
        else
        if(prim()!=0)
            v[i]=prim(),++nr,fr[v[i]]++;
    }
    cout<<nr<<'\n';
    for(i=1; i<=n; ++i)
        cout<<v[i]<<' ';
}
