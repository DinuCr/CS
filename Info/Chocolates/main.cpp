#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[200005];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int i,n;
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    ll ans = 0;
    int curr = v[n]+1;
    for(i=n; i>0; --i)
    {
        if(curr>1)
            ans+=min(curr-1,v[i]);
        curr = min(curr-1,v[i]);
    }
    cout<<ans;
}
