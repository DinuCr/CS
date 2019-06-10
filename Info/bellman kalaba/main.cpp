#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("kalaba.in");

#define inf LONG_MAX
#define nmax 100
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <pair<int,int> > g[nmax];
int dp[nmax][nmax];
int n,a,m,i,j;

int main()
{
    fin>>n>>m>>a;
    for(i=1; i<=m; ++i)
    {
        int x,y,cst;
        fin>>x>>y>>cst;
        g[y].pb(mp(x,cst));
    }
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            dp[i][j]=inf;
    for(auto it:g[a])
        dp[1][it.f]=it.s;
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=n; ++j)
        if(dp[i][j]!=inf)
        {
            for(auto it:g[j])
                dp[i+1][it.f]=min(dp[i][j]+it.s,dp[i+1][it.f]);
        }
    }
    cout<<dp[3][1];
}
