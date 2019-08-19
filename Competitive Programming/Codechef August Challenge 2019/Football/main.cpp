#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[200],w[200],n,t,i;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans = 0;
        for(i=1; i<=n; ++i)
            cin>>v[i];
        for(i=1; i<=n; ++i)
            cin>>w[i];
        for(i=1; i<=n; ++i)
            ans = max(ans, v[i]*20-w[i]*10);
        cout<<ans<<'\n';
    }
}
