#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("distante.in");
ofstream fout("distante.out");

#define inf 1000000000
#define nmax 50100
#define f first
#define s second

priority_queue < pair <int,int>, vector < pair <int,int> >, greater < pair <int,int> > > h;
vector < pair <int,int> > v[nmax];
bool used[nmax];
int ans[nmax];
int d[nmax];

void solve()
{
    int n,m,s,i,a,b,cost;
    fin>>n>>m>>s;
    for(i=1; i<=n; ++i)
        fin>>d[i];
    for(i=1; i<=m; ++i)
    {
        fin>>a>>b>>cost;
        v[a].push_back(make_pair(cost,b));
        v[b].push_back(make_pair(cost,a));
    }
    for(i=1; i<=n; ++i)
        ans[i]=inf;
    ans[s]=0;
    h.push(make_pair(0,s));

    while(h.size())
    {
        int nod = h.top().s;
        h.pop();
        used[nod]=1;

        for(i=0; i<v[nod].size(); ++i)
            if(!used[v[nod][i].s] && ans[nod]+v[nod][i].f<ans[v[nod][i].s])
            {
                ans[v[nod][i].s]=ans[nod]+v[nod][i].f;
                h.push(make_pair(ans[v[nod][i].s],v[nod][i].s));
            }
    }
    int ok=1;
    for(i=1; i<=n; ++i)
    {
        if(d[i]!=ans[i])
            ok=0;
    }

    if(ok)
        fout<<"DA\n";
    else
        fout<<"NU\n";

    for(i=1; i<=n; ++i)
    {
        ans[i]=0;
        v[i].clear();
        used[i]=0;
    }
}

int main()
{
    int t;
    fin>>t;
    for(int i=1; i<=t; ++i)
        solve();
}
