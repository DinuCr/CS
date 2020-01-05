#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ll fact[251000];

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	ll n,m;
	cin>>n>>m;
	ll ans = 0;

	fact[0]=1;
	for(ll i=1; i<=n; ++i)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=m;
    }
	for(ll i=0; i<n; ++i)
    {
        ll cnt = 1LL*(n-i)*(n-i);
        cnt %= m;
        cnt *= fact[i+1];
        cnt %= m;
        cnt *= fact[n-i-1];
        cnt %= m;
        ans += cnt;
        ans %= m;
    }
    cout<<ans;
}
