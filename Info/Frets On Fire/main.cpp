#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int n,i;
ll v[100100];
ll d[100100];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(i=1; i<n; ++i)
        v[i]=v[i+1]-v[i];
    --n;
    sort(v+1,v+n+1);
    for(i=1; i<=n; ++i)
        d[i]=d[i-1]+v[i];
    int q;
    cin>>q;
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        x = y-x+1;
        int pos = lower_bound(v+1,v+n+1,x+1)-v;
        ll ans = d[pos-1];
        ans+=x+(n-pos+1)*x;
        cout<<ans<<' ';
    }
}
