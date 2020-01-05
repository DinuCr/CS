#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	ll t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        ll x = 0;
        ll y = 0;
        for(ll i=1; i<=n; ++i)
        {
            ll p;
            cin>>p;
            x += p;
            y ^= p;
        }
        cout<<2<<'\n';
        cout<<y<<' '<<x+y<<'\n';
    }
}
