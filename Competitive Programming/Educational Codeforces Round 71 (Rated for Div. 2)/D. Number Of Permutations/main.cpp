#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int mod = 998244353;
pair<int,int> v[300100];

bool cmp1(pair<int,int> a, pair<int,int> b)
{
    return a.f<b.f;
}


bool cmp2(pair<int,int> a, pair<int,int> b)
{
    return a.s<b.s;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n,i;

    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i].f>>v[i].s;

    sort(v+1,v+n+1,cmp1);

    ll ans = 1;

    ll curr = 1;

    ll cnt = 0;

    ll ANS =1;
    for(i=1; i<=n; ++i)
        ANS *= i, ANS = ANS % mod;

    for(i=1; i<=n; ++i)
        if(v[i].f!=v[i-1].f)
            ans*=curr,ans=ans%mod,curr=1,cnt=1;
        else
            curr*=cnt+1,cnt++,curr=curr%mod;

    ans*=curr,ans=ans%mod;
    ANS -= ans;


    if(ANS < 0)
        ANS += mod;

    sort(v+1,v+n+1,cmp2);

    ans = 1;

    curr = 1;

    cnt = 0;

    for(i=1; i<=n; ++i)
        if(v[i].s!=v[i-1].s)
            ans*=curr,ans=ans%mod,curr=1,cnt=1;
        else
            curr*=cnt+1,cnt++,curr=curr%mod;
    ans*=curr,ans=ans%mod;

     ANS -= ans;

    if(ANS < 0)
        ANS += mod;

    sort(v+1,v+n+1);

    ans = 1;

    curr = 1;

    cnt = 0;

    int ok = 1;

    for(i=1; i<=n; ++i)
        if(v[i].f<v[i-1].f || v[i].s<v[i-1].s)
            ok=0;

    for(i=1; i<=n && ok; ++i)
        if(v[i].f!=v[i-1].f || v[i].s!=v[i-1].s)
            ans*=curr,ans=ans%mod,curr=1,cnt=1;
        else
            curr*=cnt+1,cnt++,curr=curr%mod;
    ans*=curr,ans=ans%mod;

    if(ok)
    ANS += ans;

    if(ANS < 0)
        ANS += mod;



    cout<<ANS%mod;
}
