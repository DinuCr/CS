#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax (int) 1e5+10

int v[nmax];
int n,m,i,curr;

int gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main()
{
    cin>>n>>m>>curr;
    v[1]=curr;
    for(i=2; i<=n; ++i)
    {
        cin>>v[i];
        curr=gcd(curr,v[i]);
    }
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        v[a]/=b;
        curr=gcd(curr,v[a]);
        cout<<curr<<'\n';
    }
}
