#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

ifstream fin("sprim.in");
ofstream fout("sprim.out");

#define fact (int)1e6+100
#define nmax (int)1e5+100

int prim[fact];
int era[fact];
int curr[fact];
int v[nmax];
int ans[nmax];
int last[nmax];
int i,n,x,k,l;

int main()
{
    fin>>n;

    k = 100;
    for(i=2; i<=k; ++i)
    {
        for(int j=i*i; j<=1000; j+=i)
            era[j]=1;
    }
    int m=0;
    for(i=2; i<=1000; ++i)
        if(!era[i])
            prim[m++]=i;
    prim[m++]=100000;

    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
        l = 0;
        k = sqrt(v[i]);
        x = v[i];

        for(int j=0; prim[j]<=k; ++j)
        {
            if(x%prim[j]==0)
            {
                l=max(l,curr[prim[j]]);
                x/=prim[j];
                curr[prim[j]]=i;
                while(x%prim[j]==0)
                    x/=prim[j];
            }
        }

        if(x!=1)
        {
            l=max(curr[x],l);
            curr[x]=i;
        }
        last[i]=l;
    }
    for(i=1; i<=n; ++i)
        ans[i]=max(ans[i-1],last[i]+1);
    int x=0;
    for(i=1; i<=n; ++i)
        x+=i-ans[i];
    fout<<x;
}
