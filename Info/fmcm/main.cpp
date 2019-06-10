#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

#define nmax 355
#define inf 1000000000
#define mp make_pair
#define f first
#define s second

vector <int> v[nmax];
int c[nmax][nmax];
int f[nmax][nmax];
int cst[nmax][nmax];
int t[nmax];
int viz[nmax];
int d[nmax];
int used[nmax];
int n,a,b,m;

bool bf()
{
    queue <int> h;
    for(int i=1; i<=n; ++i)
        d[i]=inf;
    h.push(a);
    used[a]=1;
    d[a]=0;
    while(!h.empty())
    {
        int nod = h.front();
        h.pop();
        used[nod]=0;
        for(auto it:v[nod])
        {
            if(f[nod][it]<c[nod][it] && d[nod]+cst[nod][it]<d[it])
            {
                d[it]=d[nod]+cst[nod][it];
                t[it]=nod;
                if(!used[it])
                {
                    used[it]=1;
                    h.push(it);
                }
            }
        }
    }
    return d[b]!=inf;
}



int main()
{
    fin>>n>>m>>a>>b;
    while(m--)
    {
        int x,y,q,z;
        fin>>x>>y>>q>>z;
        c[x][y]=q;
        cst[x][y]=z;
        cst[y][x]=-z;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans = 0;
    while(bf())
    {
            int flow = inf;
            for(int i = b; i!=a; i=t[i])
                flow = min(flow,c[t[i]][i]-f[t[i]][i]);
            if(!flow)
                continue;
            for(int i = b; i!=a; i=t[i])
            {
                f[t[i]][i]+=flow;
                f[i][t[i]]-=flow;
                ans+=flow*cst[t[i]][i];
            }
    }
    fout<<ans;
}
