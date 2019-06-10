#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

#define f first
#define s second

ifstream f("sate.in");
ofstream g("sate.out");

vector < pair <int,int> > v[30100];
queue <int> q;
int d[30100];
int n,m,i,x,y,a,b,cost;

int main()
{
    f>>n>>m>>x>>y;
    for(i=1; i<=m; ++i)
    {
        f>>a>>b>>cost;
        v[a].push_back(make_pair(cost,b));
        v[b].push_back(make_pair(-cost,a));
    }
    q.push(x);
    for(i=1; i<=n; ++i)
        d[i]=-1;
    d[x]=0;
    while(d[y]==-1 && !q.empty() )
    {
        a=q.front();
        q.pop();
        for(i=0; i<v[a].size(); ++i)
            if(d[v[a][i].s]==-1)
            {
                d[v[a][i].s]=d[a]+v[a][i].f;
                q.push(v[a][i].s);
            }
    }
    g<<d[y];
}
