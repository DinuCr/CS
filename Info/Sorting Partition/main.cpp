#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax (int) 1e5+10

int v[nmax];
int d[nmax];
int i,n,ans;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    d[n]=v[n];
    for(i=n-1; i>0; --i)
        d[i]=min(d[i+1],v[i]);
    int curr = v[1];
    for(i=1; i<=n; ++i)
        if(curr<=d[i+1])
            ++ans,curr=v[i+1];
        else
            curr=max(curr,v[i]);
    ++ans;
    cout<<ans;
}
