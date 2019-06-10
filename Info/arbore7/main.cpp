#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("arbore7.in");
ofstream fout("arbore7.out");

#define nmax 100010
#define ll long long

vector <int> v[nmax];
int cnt[nmax][2];
int dp[nmax][2];

const int modulo = 1e9+7;

inline int mod(ll x)
{
    if(x>=modulo)
        return x%modulo;
    return x;
}

void df(int x,int t)
{
    cnt[x][0]=1;
    dp[x][0]=dp[x][1]=1;
    for(auto it:v[x])
        if(it!=t)
        {
            df(it,x);

            if(cnt[it][0]-1==cnt[it][1])
            {
                cnt[x][0]+=cnt[it][1];
                dp[x][0]=mod(1LL*dp[x][0]*(dp[it][0]+dp[it][1]));
            }
            else
            if(cnt[it][0]-1>cnt[it][1])
            {
                cnt[x][0]+=cnt[it][0]-1;
                dp[x][0]=mod(1LL*dp[x][0]*dp[it][0]);
            }
            else
            {
                cnt[x][0]+=cnt[it][1];
                dp[x][0]=mod(1LL*dp[x][0]*dp[it][1]);
            }


            if(cnt[it][0]==cnt[it][1])
            {
                cnt[x][1]+=cnt[it][0];
                dp[x][1]=mod(1LL*dp[x][1]*(dp[it][0]+dp[it][1]));
            }
            else
            if(cnt[it][0]>cnt[it][1])
            {
                cnt[x][1]+=cnt[it][0];
                dp[x][1]=mod(1LL*dp[x][1]*dp[it][0]);
            }
            else
            {
                cnt[x][1]+=cnt[it][1];
                dp[x][1]=mod(1LL*dp[x][1]*dp[it][1]);
            }
        }
}

int main()
{
    int n,i,a,b;
    fin>>n;
    for(i=1; i<n; ++i)
    {
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    df(1,0);
    fout<<max(cnt[1][0],cnt[1][1])<<' ';
    if(cnt[1][0]>cnt[1][1])
        fout<<dp[1][0];
    else
    if(cnt[1][0]==cnt[1][1])
        fout<<mod(dp[1][1]+dp[1][0]);
    else
        fout<<dp[1][1];
}
