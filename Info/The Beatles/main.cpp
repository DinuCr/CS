#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ll n,mn=1e12,mx,N,k,a,b;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void compute(ll r)
{
    for(ll i=0; i<=n; ++i)
    if(r+i*k>0)
    {
        mn=min(mn,N/gcd(r+i*k,N));
        mx=max(mx,N/gcd(r+i*k,N));
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n>>k;
    cin>>a>>b;

    N = n*k;

    ll x1 = (k+1)-a;
    ll x2 = (k+1)+a;
    ll x3 = (k+1)-b;
    ll x4 = (k+1)+b;


    compute(x3-x1);
    compute(x3-x2);
    compute(x4-x2);
    compute(x4-x1);
    cout<<mn<<' '<<mx;
}
