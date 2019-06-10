#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax (int)1e5+10

vector <int> v[nmax];
vector <int> w[nmax];
int used[nmax];
int i,n,m,x,k;

void df1(int x)
{
    used[x]=1,++k;
    for(auto it:v[x])
        if(!used[it])
            df1(it);
}

void df2(int x)
{
    used[x]=1,++k;
    for(auto it:w[x])
        if(!used[it])
            df2(it);
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n>>m>>x;
    for(i=1; i<=m; ++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(c<=x)
        {
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(c<x)
        {
            w[a].push_back(b);
            w[b].push_back(a);
        }
    }
    long long ans = 0;
    for(i=1; i<=n; ++i)
        if(!used[i])
        {
            k=0;
            df1(i);
            ans+=1LL*k*(k-1)/2;
        }
    memset(used, 0, sizeof(used));
    for(i=1; i<=n; ++i)
        if(!used[i])
        {
            k=0;
            df2(i);
            ans-=1LL*k*(k-1)/2;
        }
    cout<<ans;
}
