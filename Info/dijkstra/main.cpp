#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

#define mp make_pair
#define f first
#define s second
#define nmax 50100
#define inf 1000000000
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

vector < pair <int, int> > v[nmax];
priority_queue < pair <int,int>, vector < pair <int,int> >, greater < pair <int,int> > > h;
int ans[nmax],n,m,i,a,b,cost;
bool w[nmax];

int main()
{
    fin>>n>>m;
    for(i=0; i<m; ++i)
    {
        fin>>a>>b>>cost;
        v[a].push_back(mp(cost,b));
    }
    ans[1]=0;
    for(i=2; i<=n; ++i)
        ans[i]=inf;
    h.push(mp(0,1));
    while(h.size())
    {
        int nod=h.top().s;
        h.pop();
        if(w[nod])
            continue;
        w[nod]=1;
        for(i=0; i<v[nod].size(); ++i)
        {
            if(!w[v[nod][i].s] && ans[nod]+v[nod][i].f<ans[v[nod][i].s])
            {
                ans[v[nod][i].s]=ans[nod]+v[nod][i].f;
                h.push(mp(ans[v[nod][i].s],v[nod][i].s));
            }
        }
    }
    for(i=2; i<=n; ++i)
        if(ans[i]==inf)
            fout<<"0 ";
        else
            fout<<ans[i]<<' ';

}
