#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

#define nmax (int)(2e5)+10

const int MOD = 1e9+7;

vector <int> v[nmax];
int comp;
int used[nmax];
int nr[nmax];
int n,k,i;

ll mod(ll x)
{
    if(x>=MOD)
        return x%MOD;
    return x;
}

void df(int x)
{
    used[x]=comp;
    nr[comp]++;
    for(auto it:v[x])
        if(!used[it])
            df(it);
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n>>k;
    for(i=1; i<n; ++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(z==0)
            v[x].pb(y),v[y].pb(x);
    }
    for(i=1; i<=n; ++i)
    if(!used[i])
    {
        ++comp;
        df(i);
    }
    ll ans = 1;
    for(i=1; i<=k; ++i)
        ans=mod((ll)ans*n);
    ll sc = 0;
    for(i=1; i<=comp; ++i)
    {
        ll curr = 1;
        for(int j=1; j<=k; ++j)
            curr = mod(curr*nr[i]);
        sc = mod(sc+curr);
    }
    ans-=sc;
    if(ans<0)
        ans+=MOD;
    cout<<ans;
}
