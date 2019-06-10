#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[101000];
int w[101000];
int m,n,i,mx=0,mn=1e9;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        mx = max(mx,v[i]);
    }
    for(i=1; i<=m; ++i)
    {
        cin>>w[i];
        mn = min(mn,w[i]);
    }
    if(mx>mn)
    {
        cout<<-1;
        return 0;
    }
    ll ans = 0;
    for(i=1; i<=n; ++i)
        ans+=1LL*m*v[i];
    int cnt=0;
    for(i=1; i<=m; ++i)
        if(mx<w[i])
            cnt++;
    if(cnt!=m)
        for(i=1; i<=m; ++i)
            ans+=w[i]-mx;
    else
    {
        int mx1 = 0;
        int mx2 = 0;
        for(i=1; i<=n; ++i)
            if(v[i]>=mx1)
            {
                mx2=mx1;mx1=v[i];
            }
            else
            if(v[i]>mx2)
                mx2=v[i];
        for(i=1; i<m; ++i)
            ans+=w[i]-mx1;
        ans+=w[m]-mx2;
    }
    cout<<ans;
}
