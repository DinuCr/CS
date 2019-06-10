#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

pair<ll,ll> v[(ll)2e5 + 10];
ll n;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    n<<=1;
    ll i;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i].f;
        v[i].s=i;
    }

    sort(v+1,v+n+1);

    ll a = 1;
    ll b = 1;
    ll ansa = 0;
    ll ansb = 0;
    for(i=1; i<=n; i+=2)
    {
        if(abs(v[i].s-a) + abs(v[i+1].s-b) < abs(v[i].s-b) + abs(v[i+1].s-a))
        {
            ansa+=abs(v[i].s-a);
            a = v[i].s;
            ansb+=abs(v[i+1].s-b);
            b = v[i+1].s;
        }
        else
        {
            ansa+=abs(v[i+1].s-a);
            a = v[i+1].s;
            ansb+=abs(v[i].s-b);
            b = v[i].s;
        }
    }
    cout<<ansa+ansb;
}
