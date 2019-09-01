#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

queue <int> qu;
vector <int> q[1000];
ll v[101000];
ll w[101000];
int used[1000];
int t[1000];
int ans,n,i,j;

int countt(ll x)
{
    int cnt = 0;
    while(x)
    {
        x=x&(x-1);
        cnt++;
    }
    return cnt;
}

void bfs()
{
    while(!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        for(auto it:q[x])
            if(used[it])
            {
                if(t[x]!=it)
                    ans = min(used[x]+used[it]-1,ans);
            }
            else
            {
                used[it]=used[x]+1;
                t[it]=x;
                qu.push(it);
            }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;

    for(i=1; i<=n; ++i)
        cin>>v[i];

    for(i=0; i<=62; ++i)
    {
        int cnt = 0;
        ll p = 1LL<<i;
        for(j=1; j<=n; ++j)
            if(p&v[j])
                cnt++;
        if(cnt>=3)
        {
            cout<<'3';
            return 0;
        }
    }

    int k = 1;
    for(i=1; i<=n; ++i)
        if(countt(v[i])>1)
            w[k++]=v[i];
    n = k;
    for(i=1; i<=n; ++i)
        for(j=i+1; j<=n; ++j)
            if(w[i]&w[j])
                q[i].pb(j),q[j].pb(i);
    ans = 10000;
    for(i=1; i<=n; ++i)
    {
        memset(used, 0, sizeof(used));
        memset(t, 0, sizeof(t));
        qu.push(i);
        t[i]=1;
        used[i]=1;
        bfs();
    }
    if(ans==10000)
        cout<<-1;
    else
        cout<<ans;
}
