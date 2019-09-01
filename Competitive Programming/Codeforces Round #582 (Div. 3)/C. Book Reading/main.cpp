#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    ll t,n,m;

    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        vector<int> v;
        v.pb(m%10);
        ll x = (m+m)%10;
        ll ans = 0;
        while(x%10!=v[0])
        {
            v.pb(x);
            x=x+m;
            x%=10;
        }
        ll sum = 0;
        for(auto it: v)
            sum+=it;

        n/=m;

        while(n%v.size()!=0)
        {
            ans+=v[(n%v.size()-1)%v.size()];
            n--;
        }

        ans+=sum*n/v.size();
        cout<<ans<<'\n';
    }
}
