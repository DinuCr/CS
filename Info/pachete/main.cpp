#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("pachete.in");
ofstream g("pachete.out");

int d[100100],v[100100],p[100100],i,n,s;

int gcd(int a,int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

bool compare(int a,int b)
{
    return d[a]>d[b];
}

int main()
{
    f>>n>>v[1];
    for(i=2; i<=n; ++i)
    {
        f>>v[i];
        d[i]=gcd(v[i],v[i-1]);
        p[i-2]=i;
    }

    sort(p,p+n,compare);

    for(i=1; i<=n; ++i)
        v[i]=0;

    n--;
    for(i=0; i<n; ++i)
    {
        if(v[p[i]]==0 && v[p[i]-1]==0)
        {
            if(d[p[i]]>=d[p[i]-1]+d[p[i]+1])
            {
                v[p[i]]=1;
                v[p[i]-1]=1;
                s+=d[p[i]];
            }
        }
    }
    for(i=0; i<n; ++i)
    {
        if(v[p[i]]==0 && v[p[i]-1]==0)
        {
            if(d[p[i]]>=d[p[i]-1] && d[p[i]]>=d[p[i]+1])
            {
                v[p[i]]=1;
                v[p[i]-1]=1;
                s+=d[p[i]];
            }
        }
    }
    for(i=0; i<n; ++i)
    {
        if(v[p[i]]==0 && v[p[i]-1]==0)
        {
            v[p[i]]=1;
            v[p[i]-1]=1;
            s+=d[p[i]];
        }
    }
    g<<s;
}
