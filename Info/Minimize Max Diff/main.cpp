#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax (int)1e5+10

int rmq[nmax][17];
int v[nmax];
int i,n,k,j;

int main()
{
    cin>>n>>k;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    for(j=1; j<=17; ++j)
        for(i=1; i+(1<<j)-1<=n; ++i)
            rmq[i][j]=max(rmq[i][j-1],max(rmq[i+(1<<(j-1))][j-1],abs(v[i+(1<<(j-1))-1]-v[i+(1<<(j-1))])));
    int ans = 2e9;
    int lg = log2(n-k);
    for(i=k; i>=0; --i)
    {
        int curr = max(rmq[1+i][lg],rmq[n-(1<<lg)-(k-i)+1][lg]);
        ans = min(ans,curr);
    }
    cout<<ans;
}
