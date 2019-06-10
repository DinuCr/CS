#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ll n,m;
vector <ll> v[50001];
ll d[50001];

ll dist(ll x, ll y)
{
    if(y>=x)
        return y-x;
    else
    return n - x + y;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    ll i,j;

    cin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(i=1; i<=n; ++i)
    if(v[i].size()>0)
    {
        d[i]=n*(v[i].size()-1);
        ll mn = 2*n;
        for(auto it:v[i])
            mn=min(mn,dist(i,it));
        d[i]+=mn;
    }
    for(i=1; i<=n; ++i)
    {
        ll ans = 0;
        for(j=1; j<=n; ++j)
        {
            ans=max(ans,d[j]>0?d[j]+(ll)dist(i,j):0);
        }
        cout<<ans<<' ';
    }
}
