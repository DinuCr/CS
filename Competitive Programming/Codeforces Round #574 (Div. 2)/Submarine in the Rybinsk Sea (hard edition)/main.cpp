#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ll n,v[100100],i,j,d[100],curr;

ll mod(ll x)
{
    if(x>=1LL*998244353)
        x%=1LL*998244353;
    return x;
}

ll compose_f(int x,int cnt)
{
    ll ans = 0;
    ll p = 10;
    while(cnt && x)
    {
        cnt--;
        ans += x%10*p;
        if(cnt)
            p*=100;
        x/=10;
    }
    if(!x)
        return ans;
    else
    {
        while(x)
            p*=10,ans+=x%10*p,x/=10;
        return ans;
    }
}

ll compose_b(int x,int cnt)
{
    ll ans = 0;
    ll p = 1;
    while(cnt && x)
    {
        ans += x%10*p;
        if(cnt)
            p*=100;
        cnt--;
        x/=10;
    }
    if(!x)
        return ans;
    else
    {
        while(x)
            ans+=x%10*p,p*=10,x/=10;
        return ans;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];

    for(i=1; i<=n; ++i)
    {
        int cnt = 0;
        int x = v[i];
        while(x)
        {
            cnt++;
            x/=10;
        }
        d[cnt]++;
    }

    ll ans = 0;

    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=10; ++j)
        {
            curr = compose_f(v[i],j);
            curr = mod(curr);
            ans = mod(ans+curr*d[j]);
        }
    }

    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=10; ++j)
        {
            curr = compose_b(v[i],j);
            curr = mod(curr);
            ans = mod(ans+curr*d[j]);
        }
    }
    cout<<ans;
}

