#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

const ll modulo = 998244353;

vector <ll> v[(ll)1e6+10];
ll cnt[(ll)1e6+10];

ll mod(ll x)
{
    if(x > modulo)
        return x%modulo;
    return x;
}

ll exp(ll x, ll n)
{
    if(n==0)
        return 1;
    if(n==1)
        return x;
    if(n&1)
        return mod(x * exp(x, n-1));
    return mod(exp(mod(x*x), n>>1));
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	ll n;
	cin>>n;
	for(ll i=1; i<=n; ++i)
    {
        ll k;
        cin>>k;
        while(k--)
        {
            ll x;
            cin>>x;
            v[i].pb(x);
            cnt[x]++;
        }
    }
    ll ans = 0;
    for(ll i=1; i<=n; ++i)
    {
        for(auto it:v[i])
            ans = mod (ans + mod(1LL*cnt[it]*exp(mod(1LL*mod(n*n)*v[i].size()), modulo-2)));
    }
    cout<<ans;
}
