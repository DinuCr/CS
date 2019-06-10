#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

ifstream fin("maxflow.in");
ofstream fout("maxflow.out");

#define nmax 1010

const int inf = 1e9;

vector <int> v[nmax];
int c[nmax][nmax];
int f[nmax][nmax];
int viz[nmax];
int t[nmax];
int flow,fmin,n,m,i;

int bf()
{
    memset(viz, 0, sizeof(viz));

    queue<int> q;
    q.push(1);

    viz[1]=1;
    int nod;
    while(!q.empty())
    {
        nod = q.front();
        q.pop();
        if(nod==n)
            continue;
        for(auto it:v[nod])
        {
            if(f[nod][it]>=c[nod][it] || viz[it])
                continue;
            viz[it]=1;
            q.push(it);
            t[it]=nod;
        }
    }
    return viz[n];
}

int main()
{
    fin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        int a,b,z;
        fin>>a>>b>>z;
        v[a].push_back(b);
        v[b].push_back(a);
        c[a][b]+=z;
    }
    while(bf())
    {
        for(auto it:v[n])
        {
            if(f[it][n]>=c[it][n] || !viz[it])
                continue;
            t[n]=it;
            fmin=inf;

            for(i=n; i>1; i=t[i])
                fmin=min(fmin,c[t[i]][i]-f[t[i]][i]);

            if(!fmin)
                continue;

            for(i=n; i>1; i=t[i])
            {
                f[t[i]][i]+=fmin;
                f[i][t[i]]-=fmin;
            }
            flow+=fmin;
        }
    }
    fout<<flow;
}
