#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ll v[310000];
ll n,i;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;

    for(i=1; i<=n; ++i)
    {
        v[i]=2*i-1, v[n+i]=2*i;
        if(i%2==0)
            swap(v[i],v[n+i]);
    }
    ll mn = 1e15;
    ll mx = 0;
    ll curr = 0;
    for(i=1; i<=n; ++i)
        v[2*n+i]=v[i];
    for(i=1; i<=3*n; ++i)
    {
        if(i<=n)
            curr+=v[i];
        else
        {
            curr+=v[i];
            curr-=v[i-n];
        }
        if(i>=n)
        mn = min(mn,curr), mx = max(mx,curr);
    }
    if(mx-mn<2)
    {
        cout<<"YES\n";
        for(i=1; i<=2*n; ++i)
            cout<<v[i]<<' ';
    }
    else
        cout<<"NO";
}
