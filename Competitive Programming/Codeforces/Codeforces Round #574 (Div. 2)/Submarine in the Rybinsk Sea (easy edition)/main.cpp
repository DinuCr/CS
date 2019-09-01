#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ll n,v[100100],i;

ll mod(ll x)
{
    if(x>=1LL*998244353)
        x%=1LL*998244353;
    return x;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];

    ll ans = 0;

    for(i=1; i<=n; ++i)
    {
        ll x = v[i];
        ll curr = 0;
        ll p = 10;
        while(x)
        {
            curr += x%10*p;
            p*=100;
            x/=10;
        }
        curr = mod(curr);
        ans=mod(ans+curr*n);
    }
    for(i=1; i<=n; ++i)
    {
        ll x = v[i];
        ll curr = 0;
        ll p = 1;
        while(x)
        {
            curr += x%10*p;
            p*=100;
            x/=10;
        }
        curr = mod(curr);
        ans=mod(ans+curr*n);
    }
    cout<<ans;
}

