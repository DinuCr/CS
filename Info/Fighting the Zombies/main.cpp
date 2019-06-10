#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("zombies.in");
ofstream fout("zombies.out");

#define f first
#define s second

pair<int,int> v[5550];
long long w[5550];
long long p[5550];
long long x[5550];
long long y[5550];

int i,t,k,n,r,m,j;

inline int cnter(long long n)
{
    int num = 0;
    if (n)
        do num++;
        while (n &= n - 1);
    return num;
}

int main()
{
    p[0]=1;
    for(i=1; i<=51; ++i)
        p[i]=1LL*p[i-1]*2;
    fin>>t;
    for(k=1; k<=t; ++k)
    {
        fin>>n>>r;
        for(i=1; i<=n; ++i)
            fin>>x[i]>>y[i];
        m=0;
        for(i=1; i<=n; ++i)
            for(j=i; j<=n; ++j)
            {
                v[++m].f=x[i];
                v[m].s=y[j];

                v[++m].f=x[j];
                v[m].s=y[i];
            }
        memset(w, 0, sizeof(w));
        for(i=1; i<=m; ++i)
        {
            for(j=1; j<=n; ++j)
                if(v[i].f<=x[j] && x[j]<=v[i].f+r && v[i].s<=y[j] && y[j]<=v[i].s+r)
                    w[i]+=p[j];
        }
        int ans = 0;
        long long x;
        for(i=1; i<m; ++i)
            for(j=i+1; j<=m; ++j)
            {
                x = w[i]|w[j];
                ans = max(ans,cnter(x));
            }
        fout<<"Case #"<<k<<": "<<ans<<'\n';
    }
}
