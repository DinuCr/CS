#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define nmax (long long) 1e5+10

ll n,ans,k;
ll v[nmax];

bool cmp(long long a,long long b)
{
    if(a%2 != b%2)
        return a%2<b%2;
    else
    return a<b;
}

int main()
{
    ll i,curr=0;
    cin>>n>>k;
    for(i=1; i<=n; ++i)
        cin>>v[i],--v[i];
    ans = n;
    sort(v+1,v+n+1,cmp);
    for(i=1; i<=n; ++i)
    {
        if(1LL*(v[i]+1)/2+1LL*curr<k)
        {
            ans+=v[i];
            curr+=(v[i]+1)/2;
        }
        else
        {
            ans+=(k-curr)*2-1;
            curr=k;
            break;
        }
    }
    if(curr!=k)
        cout<<-1;
    else
        cout<<ans;
}
