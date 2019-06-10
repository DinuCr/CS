#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[300100];
int n,i;
ll ans;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    ll curr = 0;
    for(i=1; i<=n; ++i)
    {
        ll a = min(curr,1LL*v[i]/2);
        ans+=a;
        v[i]-=a*2;
        curr-=a;
        ans+=v[i]/3;
        v[i]=v[i]%3;
        curr+=v[i];
    }
    cout<<ans;
}
