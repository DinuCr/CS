#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

ifstream fin("joc4.in");
ofstream fout("joc4.out");

#define nmax 510

vector <int> v[nmax];

char f[nmax][nmax];
char c[nmax][nmax];
int t[nmax];
int used[nmax];
int n,m,a,b,i,flow,maxflow;

bool bf()
{
    memset(used, 0, sizeof(used));
    used[a<<1]=1;
    used[a<<1|1]=1;

    queue <int> q;
    q.push(a<<1|1);

    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        if(nod == b)
            continue;
        for(auto it:v[nod])
        {
            if(used[it] || f[nod][it]==c[nod][it])
                continue;
            t[it]=nod;
            used[it]=1;
            q.push(it);
        }
    }
    return used[b];
}

int main()
{
    fin>>n>>m>>a>>b;
    b<<=1;
    for(i=1; i<=m; ++i)
    {
        int x,y;
        fin>>x>>y;
        v[x<<1|1].push_back(y<<1);
        v[y<<1].push_back(x<<1|1);
        c[x<<1|1][y<<1]=1;
        v[y<<1|1].push_back(x<<1);
        v[x<<1].push_back(y<<1|1);
        c[y<<1|1][x<<1]=1;
    }
    for(i=1; i<=n; ++i)
    {
        v[i<<1].push_back(i<<1|1);
        c[i<<1][i<<1|1]=1;
        v[i<<1|1].push_back(i<<1);
    }
    int q = a<<1|1;
    while(bf())
    {
        for(auto it:v[b])
        {
            if(!used[it] || f[it][b]==c[it][b])
                continue;
            t[b]=it;
            flow = 1e9;
            for(i=b; i!=q; i=t[i])
                flow=min(flow,c[t[i]][i]-f[t[i]][i]);

            if(!flow)
                continue;

            for(i=b; i!=q; i=t[i])
            {
                f[t[i]][i]+=flow;
                f[i][t[i]]-=flow;
            }
            maxflow+=flow;
        }
    }
    fout<<maxflow;
}
