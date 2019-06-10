#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("bibel.in");
ofstream fout("bibel.out");

struct point
{
    int x,y;
};

inline int dist(point a,point b)
{
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

#define nmax 18

inline int p(int x)
{
    return 1<<x;
}

const int inf = 1000000000;

point curr[nmax];
point last[nmax];
int lastd[nmax];
int d[nmax][nmax];
int dp[(1<<nmax)][nmax];
int n,lastn;

void solve()
{
    int i,j,k;
    int x = (1<<n);

    for(i=0; i<n; ++i)
        for(j=0; j<n; ++j)
            d[i][j]=dist(curr[i],curr[j]);

    for(i=1; i<x; ++i)
        for(j=0; j<n; ++j)
            dp[i][j]=inf;

    for(i=0; i<n; ++i)
        for(j=0; j<lastn; ++j)
            dp[p(i)][i]=min(dp[p(i)][i],lastd[j]+dist(last[j],curr[i]));

    for(i=1; i<x; ++i)
        for(j=0; j<n; ++j)
            if(i & p(j))
                for(k=0; k<n; ++k)
                    if(i & p(k) && k!=j)
                        dp[i][j]=min(dp[i][j],dp[i^p(j)][k] + d[k][j]);

    lastn=n;
    for(i=0; i<n; ++i)
        last[i]=curr[i];
    int ans = inf;
    for(i=0; i<n; ++i)
    {
        lastd[i]=dp[x-1][i];
        ans=min(ans,lastd[i]);
    }
    fout<<ans<<'\n';
    n=0;
}

int main()
{
    lastn=1;
    lastd[1]=0;
    last[0].x=last[0].y=0;
    int x,a,b;
    fin>>x;
    while(x!=2)
    {
        if(x==1)
            solve();
        else
        {
            fin>>curr[n].x>>curr[n].y;
            ++n;
        }
        fin>>x;
    }
}
