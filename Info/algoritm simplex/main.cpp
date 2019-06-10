#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;

ifstream fin("simplex.in");

#define inf LONG_MAX
#define nmax 105
#define f first
#define s second
#define mp make_pair

priority_queue <pair<int,int>, vector <pair<int,int> > , greater<pair<int,int> > >q;
vector <pair<int,int> > v[nmax];
vector <int> g[nmax];
vector <int> ans;
int d[nmax];
int a,b,n,m,i;

void df(int x)
{
    if(x!=a)
    {
        for(auto it:g[x])
        {
            ans.push_back(it);
            df(it);
            ans.pop_back();
        }
    }
    else
    {
        cout<<b<<' ';
        for(auto it:ans)
            cout<<it<<' ';
        cout<<'\n';
    }
}

int main()
{
    fin>>n>>m>>a>>b;
    for(i=1; i<=n; ++i)
        d[i]=inf;
    for(i=1; i<=m; ++i)
    {
        int x,y,cst;
        fin>>x>>y>>cst;
        v[x].push_back(mp(cst,y));
    }
    q.push(mp(0,a));
    d[a]=0;
    while(q.size())
    {
        int nod = q.top().s;
        if(d[nod]!=q.top().f)
        {
            q.pop();
            continue;
        }
        q.pop();
        for(auto it:v[nod])
        {
            if(d[nod]+it.f<d[it.s])
            {
                d[it.s]=d[nod]+it.f;
                q.push(mp(d[it.s],it.s));
                g[it.s].clear();
                g[it.s].push_back(nod);
            }
            else
            if(d[nod]+it.f==d[it.s])
            {
                g[it.s].push_back(nod);
            }
        }
    }
    cout<<d[b]<<'\n';
    df(b);
}
