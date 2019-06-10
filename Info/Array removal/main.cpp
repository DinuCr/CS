#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax (ll)1e5+10
#define ll long long

ll t[nmax];
ll q[nmax];
ll sum[nmax];
ll v[nmax];
ll used[nmax];

ll root(ll x)
{
    if(!t[x])
        return x;
    return t[x]=root(t[x]);
}

int main()
{
    ll n,i;
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    for(i=1; i<=n; ++i)
        cin>>q[i];
    stack <ll> ans;
    ll prev = 0;
    for(i=n; i>0; --i)
    {
        used[q[i]]=1;
        sum[q[i]]=v[q[i]];
        if(used[q[i]-1])
        {
            sum[root(q[i]-1)]+=sum[root(q[i])];
            t[root(q[i])]=root(q[i]-1);
        }
        if(used[q[i]+1])
        {
            sum[root(q[i])]+=sum[root(q[i]+1)];
            t[root(q[i]+1)]=root(q[i]);
        }
        ans.push(max(prev,sum[root(q[i])]));
        prev = max(prev,sum[root(q[i])]);
    }
    while(!ans.empty())
        cout<<ans.top()<<'\n',ans.pop();
}
