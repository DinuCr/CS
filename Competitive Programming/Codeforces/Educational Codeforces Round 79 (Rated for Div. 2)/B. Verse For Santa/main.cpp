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
        ll v[(ll)(1e5)+10];
        ll d[(ll)(1e5)+10];
        int n,s;
        cin>>n>>s;
        for(ll i=1; i<=n; ++i)
            cin>>v[i];
        d[0]=0;
        for(ll i=1; i<=n; ++i)
            d[i]=d[i-1]+v[i];
        if(d[n]<=s)
        {
            cout<<"0\n";
            continue;
        }
        ll ans = 0;
        ll mx = 0;
        for(ll i=1; i<=n; ++i)
        {
            ll step = 1;
            for( ; step<=n; step<<=1);

            int curr = 0;
            for( ; step; step>>=1)
                if(curr+step<=n)
                {
                    ll sum = d[curr+step];
                    if(curr+step>=i)
                        sum-=v[i];
                    if(sum<=s)
                        curr+=step;
                }
            if(curr>mx)
            {
                mx = curr;
                ans = i;
            }
        }
        cout<<ans<<'\n';
    }
}
