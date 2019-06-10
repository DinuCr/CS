#include <bits/stdc++.h>

using namespace std;

ifstream fin("critice.in");
ofstream fout("critice.out");

#define mp make_pair
#define nmax 1010

const int inf = 1e9;

vector <int> v[nmax];
pair<int,int> edge[nmax*10];
vector <int> ans;
int f[nmax][nmax];
int c[nmax][nmax];
int t[nmax];
int viz[nmax];
int n,m,i,j;
int flow,maxflow;

bool bf()
{
    memset(viz, 0, sizeof(viz));

    queue <int> q;
    q.push(1);
    viz[1]=1;

    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        if(nod == n)
            continue;
        for(auto it:v[nod])
        {
            if(f[nod][it]>=c[nod][it] || viz[it])
                continue;
            t[it]=nod;
            viz[it]=1;
            q.push(it);
        }
    }
    return viz[n];
}

bool way(int a,int b)
{
    queue<int> q;
    viz[a]=1;
    if(a==b)
        return 1;
    q.push(a);
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        for(auto it:v[nod])
        {
            if(viz[it] || f[nod][it]==c[nod][it])
                continue;
            viz[it]=1;
            if(it==b)
                return 1;
            q.push(it);
        }
    }
    return 0;
}

int main()
{
    fin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        int a,b,z;
        fin>>a>>b>>z;
        edge[i]=mp(a,b);
        v[a].push_back(b);
        v[b].push_back(a);
        c[a][b]+=z;
        c[b][a]+=z;
    }
    while(bf())
    {
        for(i=0; i<v[n].size(); ++i)
        {
            int nod = v[n][i];
            if(f[nod][n]==c[nod][n] || !viz[n])
                continue;
            flow = inf;
            t[n]=nod;
            for(j=n; j!=1; j=t[j])
                flow=min(flow,c[t[j]][j]-f[t[j]][j]);
            if(!flow)
                continue;
            for(j=n; j!=1; j=t[j])
            {
                f[t[j]][j]+=flow;
                f[j][t[j]]-=flow;
            }
            maxflow+=flow;
        }
    }
    int a,b;
    for(i=1; i<=m; ++i)
    {
        a=edge[i].first;
        b=edge[i].second;
        if(f[a][b]==c[a][b])
        {
            memset(viz, 0, sizeof(viz));
            if(way(1,a) && way(b,n))
                ans.push_back(i);
        }
        else if(f[b][a]==c[b][a])
        {
            memset(viz, 0, sizeof(viz));
            if(way(1,b) && way(a,n))
                ans.push_back(i);
        }
    }
    fout<<ans.size()<<'\n';
    for(auto it:ans)
        fout<<it<<'\n';
}
