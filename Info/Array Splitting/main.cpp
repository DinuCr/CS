#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ll n,k,d[300010],v[300010],ans,i;

bool cmp(ll a,ll b)
{
    return a>b;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n>>k;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    for(i=n; i>0; --i)
        d[i]=d[i+1]+v[i];
    ans = d[1];
    sort(d+2,d+n+1,cmp);
    for(i=2; i<=k; ++i)
        ans+=d[i];
    cout<<ans;
}
