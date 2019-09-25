#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ll v[200100];
ll n,i,mx;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        mx=max(mx,v[i]);
    }
    ll ans = 0;
    for(i=1; i<=n; ++i)
        if(mx-v[i]>0)
        {
            if(ans==0)
                ans = mx-v[i];
            else
                ans = __gcd(ans,mx-v[i]);
        }
    ll y = 0;
    if(ans==0)
    {
        cout<<"0 0";
        return 0;
    }
    for(i=1; i<=n; ++i)
        y += (mx-v[i])/ans;
    cout<<y<<' '<<ans;
}
