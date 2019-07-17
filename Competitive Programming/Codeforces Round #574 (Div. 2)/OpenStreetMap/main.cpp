#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int rmq[3001][3001][2];
int v[3001][3001];
int n,m,a,b;
int g,x,y,z,i,j,k;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n>>m>>a>>b;
    cin>>g>>x>>y>>z;

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            v[i][j]=g;
            g = (1LL*g*x+1LL*y)%z;
        }

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            rmq[i][j][0] = v[i][j];
    int lim = min(log2(a),log2(b));
    for(k=1; k<=lim; ++k)
    {
        for(i=1; i<=n; ++i)
            for(j=1; j<=m; ++j)
                if(i+(1<<k)-1 <=n && j+(1<<k)-1<=m)
                    rmq[i][j][1]=min(min(rmq[i][j][0],rmq[i][j+(1<<(k-1))][0]),
                                 min(rmq[i+(1<<(k-1))][j][0],rmq[i+(1<<(k-1))][j+(1<<(k-1))][0]));
        for(i=1; i<=n; ++i)
            for(j=1; j<=m; ++j)
                rmq[i][j][0]=rmq[i][j][1];
    }
    ll ans = 0;

    int p = lim;

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        if(i+a-1<=n && j+b-1<=m)
        {
            int curr = 2e9;
            int pos;
            if(a<b)
            {
                pos = j;
                while(pos + (1<<p) -1 < j+b)
                {
                    curr = min(curr, rmq[i][pos][0]);
                    curr = min(curr, rmq[i+a-(1<<p)][pos][0]);
                    pos += (1<<p);
                }
                curr = min(curr, rmq[i][j+b-(1<<p)][0]);
                curr = min(curr, rmq[i+a-(1<<p)][j+b-(1<<p)][0]);
            }
            else
            {
                pos = i;
                while(pos + (1<<p) -1 < i+a)
                {
                    curr = min(curr, rmq[pos][j][0]);
                    curr = min(curr, rmq[pos][j+b-(1<<p)][0]);
                    pos += (1<<p);
                }
                curr = min(curr, rmq[i+a-(1<<p)][j][0]);
                curr = min(curr, rmq[i+a-(1<<p)][j+b-(1<<p)][0]);
            }
            ans+=curr;
        }
    cout<<ans;
}
