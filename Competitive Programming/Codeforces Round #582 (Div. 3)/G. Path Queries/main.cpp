#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

vector <pair<ll,pair<ll,ll> > > v;
ll t[200010];
ll d[200010];
pair<ll,ll> w[200010];

ll root(ll x)
{
    if(!t[x])
        return x;
    t[x]=root(t[x]);
    return t[x];
}

ll cmp1(pair<ll,pair<ll,ll> > a, pair<ll,pair<ll,ll> > b)
{
    return a.f<b.f;
}

ll cmp(pair<ll,ll> a, pair<ll,ll> b)
{
    return a.s<b.s;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    ll n,m,i;

    cin>>n>>m;

    for(i=1; i<n; ++i)
    {
        ll a,b,x;
        cin>>a>>b>>x;
        v.pb(mp(x,mp(a,b)));
        d[i]=1;
    }
    d[n]=1;

    for(i=1; i<=m; ++i)
        cin>>w[i].f,w[i].s=i;
    sort(v.begin(),v.end(),cmp1);
    sort(w+1,w+m+1);

    ll pos = 0;
    ll ans = 0;

    for(i=1; i<=m; ++i)
    {
        while(pos<v.size() && v[pos].f<=w[i].f)
        {
            ll a,b;
            a = v[pos].s.f;
            b = v[pos].s.s;
            if(root(a)!=root(b))
            {
                ans+=d[root(a)]*d[root(b)];
                d[root(b)]+=d[root(a)];
                t[root(a)]=root(b);
            }
            ++pos;
        }
        w[i].f=ans;
    }
    sort(w+1,w+m+1,cmp);
    for(i=1; i<=m; ++i)
        cout<<w[i].f<<' ';
}
