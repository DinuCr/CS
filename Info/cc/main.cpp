#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("cc.in");
ofstream fout("cc.out");

const int inf = 1e6;

#define nmax 205
#define mp make_pair
#define f first
#define s second

priority_queue <pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int > > >q;
vector <int> v[nmax];
int cst[nmax][nmax];
int c[nmax][nmax];
int f[nmax][nmax];
int t[nmax];
int d[nmax];
int n,a,b;

bool dijkstra()
{
    for(int i=a; i<=b; ++i)
        d[i]=inf;
    d[a]=0;
    q.push(mp(0,a));
    while(!q.empty())
    {
        int nod = q.top().s,
            cost = q.top().f;
        q.pop();
        if(cost!=d[nod] || nod==b)
            continue;
        for(auto it:v[nod])
            if(d[it]>d[nod]+cst[nod][it] && f[nod][it]<c[nod][it])
            {
                d[it]=d[nod]+cst[nod][it];
                q.push(mp(d[it],it));
                t[it]=nod;
            }
    }
    return d[b]!=inf;
}

int main()
{
    fin>>n;
    int i,j,x;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
        {
            fin>>x;
            cst[i][n+j]=x;
            cst[n+j][i]=-x;
            c[i][n+j]=1;
            v[i].push_back(n+j);
            v[n+j].push_back(i);
        }
    a = 0;
    b = 2*n +1;
    for(i=1; i<=n; ++i)
    {
        v[a].push_back(i);
        c[a][i]=1;
        v[n+i].push_back(b);
        c[n+i][b]=1;
    }
    int flow, ans=0;
    while(dijkstra())
    {
        flow=inf;
        for(i=b; i!=a; i=t[i])
            flow=min(flow,c[t[i]][i]-f[t[i]][i]);
        if(!flow)
            continue;
        for(i=b; i!=a; i=t[i])
        {
            f[t[i]][i]+=flow;
            f[i][t[i]]-=flow;
            ans+=cst[t[i]][i];
        }
    }
    fout<<ans;
}
