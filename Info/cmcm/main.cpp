#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

ifstream fin("cmcm.in");
ofstream fout("cmcm.out");

const int inf = 1000000;

#define nmax 605

queue <int> q;
vector <int> v[nmax];
int c[nmax][nmax];
int f[nmax][nmax];
int cst[nmax][nmax];
int ind[nmax][nmax];
int t[nmax];
int d[nmax];
int used[nmax];
int n,m,i,qr,a,b,j;

bool bellman()
{
    memset(t, 0, sizeof(t));
    for(int i=1; i<=b; ++i)
        d[i]=inf;
    q.push(a);
    d[a]=0;
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        used[nod]=0;
        if(nod==b)
            continue;
        for(auto it:v[nod])
            if(d[nod]+cst[nod][it]<d[it] && c[nod][it]>f[nod][it])
            {
                d[it]=d[nod]+cst[nod][it];
                t[it]=nod;
                if(!used[it])
                {
                    q.push(it);
                    used[it]=1;
                }
            }
    }
    return d[b]!=inf;
}

int main()
{
    fin>>n>>m>>qr;
    int x,y,cost;
    for(i=1; i<=qr; ++i)
    {
        fin>>x>>y>>cost;
        y+=n;
        ind[x][y]=i;
        cst[x][y]=cost;
        cst[y][x]=-cost;
        c[x][y]=1;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    a=0;
    b=n+m+1;
    for(i=1; i<=n; ++i)
    {
        v[a].push_back(i);
        c[a][i]=1;
    }
    for(i=1; i<=m; ++i)
    {
        v[n+i].push_back(b);
        c[n+i][b]=1;
    }
    int ans=0,maxflow=0;
    while(bellman())
    {
        int flow = inf;
        for(i=b; i!=a; i=t[i])
            flow=min(flow,c[t[i]][i]-f[t[i]][i]);
        for(i=b; i!=a; i=t[i])
        {
            f[t[i]][i]+=flow;
            f[i][t[i]]-=flow;
            ans+=cst[t[i]][i]*flow;
        }
        maxflow+=flow;
    }
    fout<<maxflow<<' '<<ans<<'\n';
    for(i=1; i<=n+m; ++i)
        for(j=1; j<=n+m; ++j)
            if(f[i][j]>0)
                fout<<ind[i][j]<<' ';
}
