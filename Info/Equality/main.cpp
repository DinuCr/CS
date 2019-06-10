#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax (int) 1e5+10

int v[nmax];
int n,k,ans,i;
int low, high;

int main()
{
    cin>>n>>k;
    for(i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        ++v[x];
    }
    low = -1;
    high = 1e5+1;
    while(!v[++low]);
    while(!v[--high]);
    while(true)
    {
        if(high-low<=k)
        {
            cout<<ans;
            return 0;
        }
        int x = min(v[low],v[high]);
        ans+=x;
        v[low]-=x;
        v[high]-=x;
        v[low+1]+=x;
        v[high-1]+=x;
        if(!v[low])
            ++low;
        if(!v[high])
            --high;
    }
}
