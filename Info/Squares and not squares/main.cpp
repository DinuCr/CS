#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax (int) 1e6+10
#define mp make_pair
#define f first
#define s second

int v[nmax];

priority_queue < pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > sq;
priority_queue < pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > nsq;

int main()
{
    int i,n;
    long long ans = 0;
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        sq.push(mp(min((int)(x-(int)sqrt(x)*(int)sqrt(x)),(int)((int)(sqrt(x)+1)*(int)(sqrt(x)+1)-x)),i));
        if(x==0)
            nsq.push(mp(2,i));
        else
            if((int)sqrt(x)*sqrt(x)==x)
                nsq.push(mp(1,i));
            else
                nsq.push(mp(0,i));
    }
    for(i=1; i<=(n>>1); ++i)
    {
        ans+=sq.top().f;
        v[sq.top().f]=1;
        sq.pop();
    }
    for(i=1; i<=(n>>1); ++i)
    {
        if(v[nsq.top().s]==0)
        {
            ans+=nsq.top().f;
            nsq.pop();
        }
    }
    cout<<ans;
}

