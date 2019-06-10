#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

ifstream fin("steiner.in");

#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <pair<int,int> > g[100];
int t[100];
int d[100];
int n,m,i,j,v[100][100],k,l;
int nod[100];

int root(int x)
{
    if(!t[x])
        return x;
    t[x]=root(t[x]);
    return t[x];
}

void drum(int x,int y)
{
    if(x==y)
        cout<<x<<' ';
    else
    for(auto it:g[y])
        if(d[it.s]+it.f==d[y])
        {
            drum(x,it.s);
            cout<<y<<' ';
        }
}

void dijkstra (int x,int y)
{
    memset(d, 0, sizeof(d));
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > >q;
    q.push(mp(1,x));
    d[x]=1;
    while(!q.empty())
    {
        int nod = q.top().s;
        if(q.top().f!=d[nod])
        {
            q.pop();
            continue;
        }
        q.pop();
        for(auto it:g[nod])
            if(!d[it.s] || d[it.s]>d[nod]+it.f)
            {
                d[it.s]=it.f+d[nod];
                q.push(mp(d[it.s],it.s));
            }
    }
    drum(x,y);
}

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            v[i][j]=-1;
    for(i=1; i<=m; ++i)
    {
        int x,y,c;
        fin>>x>>y>>c;
        g[x].pb(mp(c,y));
        g[y].pb(mp(c,x));
        v[x][y]=v[y][x]=c;
    }
    for(k=1; k<=n; ++k)
        for(i=1; i<=n; ++i)
            for(j=1; j<=n; ++j)
            {
                if(i!=j && v[i][k]!=-1 && v[k][j]!=-1 && (v[i][j]==-1 || v[i][j]> v[i][k] + v[k][j]))
                    v[i][j]=v[i][k]+v[k][j];
            }
    vector <pair<int,pair<int,int> > >edge;
    fin>>l;
    for(i=1; i<=l; ++i)
        fin>>nod[i];
    for(i=1; i<=l; ++i)
        for(j=i+1; j<=l; ++j)
            if(v[nod[i]][nod[j]]!=-1)
                edge.pb(mp(v[nod[i]][nod[j]],mp(nod[i],nod[j])));

    sort(edge.begin(),edge.end());

    int cost_minim = 0;

    for(auto it:edge)
    {
        if(root(it.s.f)!=root(it.s.s))
        {
            t[root(it.s.f)]=root(it.s.s);
            cost_minim += it.f;
        }
    }
    cout<<cost_minim<<'\n';
    int q = 0;
    fin>>q;
    while(q--)
    {
        int x,y;
        fin>>x>>y;
        dijkstra(x,y);
    }

}
