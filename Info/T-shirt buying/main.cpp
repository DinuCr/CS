#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define mp make_pair
#define f first
#define s second

#define nmax 200100

int a[nmax];
int b[nmax];
int p[nmax];
int used[nmax];
int i,n,m,x;
priority_queue<pair<int,int>, vector <pair<int,int> >, greater<pair<int,int> > > h[4];

int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>p[i];
    for(i=1; i<=n; ++i)
        cin>>a[i];
    for(i=1; i<=n; ++i)
        cin>>b[i];
    for(i=1; i<=n; ++i)
    {
        h[a[i]].push(mp(p[i],i));
        if(a[i]!=b[i])
            h[b[i]].push(mp(p[i],i));
    }
    cin>>m;
    for(i=1; i<=m; ++i)
    {
        cin>>x;
        while(!h[x].empty() && used[h[x].top().s])
            h[x].pop();
        if(h[x].empty())
            cout<<"-1 ";
        else
        {
            cout<<h[x].top().f<<' ';
            used[h[x].top().s]=1;
            h[x].pop();
        }
    }
}
