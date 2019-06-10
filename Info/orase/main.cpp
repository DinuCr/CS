#include <iostream>
#include <fstream>
using namespace std;
ifstream f("orase.in");
ofstream g("orase.out");
int v[1000010],w[1000010],n,m,i,a,b,mx;

int main()
{
    f>>n>>m;
    m++;
    for(i=1;i<m;++i)
    {
        f>>a>>b;
        v[a]=max(v[a],b);
    }
    for(i=n;i>0;--i)
        if(v[i]>v[w[i+1]]+w[i+1]-i)
            w[i]=i;
        else
            w[i]=w[i+1];
    for(i=1;i<n;++i)
        if(v[i]!=0 && v[w[i]]!=0)
        mx=max(v[i]+v[w[i]]+w[i]-i,mx);
    g<<mx;
}
