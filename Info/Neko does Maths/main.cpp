#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

vector <ll> v;
ll a,b;

void find_div(ll x)
{
    ll k = sqrt(x);
    for(ll i=1; i<=k; ++i)
        if(x%i==0)
            v.pb(i),v.pb(x/i);
}

ll find_curr(ll x)
{
    if(a%x==0)
        return 0;
    else
    return (a/x+1)*x-a;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>a>>b;
    if(a>b)
        swap(a,b);

    if(a==b)
    {
        cout<<'0';
        return 0;
    }

    find_div(b-a);

    ll mn = 1e18;
    ll ans = 1e18;

    for(auto it:v)
    {
        ll k = find_curr(it);
        ll x = (a+k)*(b+k)/__gcd(a+k,b+k);
        if(x<mn)
            mn=x,ans=k;
        else
            if(x==mn && k<ans)
                k=ans;
    }
    cout<<ans;
}
