#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("shop.in");
ofstream fout("shop.out");

#define ll long long
#define f first
#define s second
#define mp make_pair

pair<ll,pair<ll,ll> >h[35];
ll cnt[35];

int main()
{
    ll n,c,l,i;
    fin>>n>>c>>l;
    for(i=1; i<=n; ++i)
    {
        fin>>h[i].f>>h[i].s.f;
        h[i].s.s=i;
    }
    sort(h+1,h+n+1);
    ll ans = 0;
    for(i=n; i>0 && l; --i)
    {
        ll curr = pow(c,h[i].f);
        cnt[h[i].s.s]=min(l/curr,h[i].s.f);
        ans+=cnt[h[i].s.s];
        l-=cnt[h[i].s.s]*curr;
    }
    fout<<ans<<'\n';
    for(i=1; i<=n; ++i)
        fout<<cnt[i]<<' ';
}
