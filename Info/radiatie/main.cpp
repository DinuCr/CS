#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("radiatie.in");
ofstream fout("radiatie.out");

#define nmax 16000
#define mp make_pair
#define f first
#define s second
#define pb push_back

vector <pair<int,pair<int,int> > > edge;
vector <pair<int,int> > v[nmax];
int t[nmax];
int lev[nmax];
int e[nmax<<2];
int viz[nmax];
int poz[nmax];
int father[20][nmax<<2];
int cst[20][nmax<<2];
int lca[20][nmax<<2];
int p[21];
int n,m,k,q,i;

inline int log(int x)
{
    int i=0;
    while(p[i+1]<=x)
        ++i;
    return i;
}

int root(int x)
{
    if(!t[x])
        return x;
    t[x]=root(t[x]);
    return t[x];
}

int euler(int x,int l)
{
    viz[x]=1;
    lev[x]=l;
    e[++k]=x;
    poz[x]=k;
    lca[0][k]=x;

    for(auto it:v[x])
    {
        if(viz[it.s])
            continue;
        euler(it.s,l+1);
        e[++k]=x;
        lca[0][k]=x;
        father[0][it.s]=x;
        cst[0][it.s]=it.f;
    }
}

int main()
{
    fin>>n>>m>>q;
    for(i=1; i<=m; ++i)
    {
        int x,y,cst;
        fin>>x>>y>>cst;
        edge.pb(mp(cst,mp(x,y)));
    }
    sort(edge.begin(),edge.end());
    for(i=0; i<edge.size(); ++i)
    {
        int a = root(edge[i].s.f);
        int b = root(edge[i].s.s);
        if(a!=b)
        {
            t[a]=b;
            v[edge[i].s.f].pb(mp(edge[i].f,edge[i].s.s));
            v[edge[i].s.s].pb(mp(edge[i].f,edge[i].s.f));
        }
    }
    k=0;
    euler(1,1);

    p[0]=1;
    for(i=1; i<=20; ++i)
        p[i]=p[i-1]*2;

    int depth = log(k),j;

    for(i=1; i<=depth; ++i)
    {
        for(j=1; j<=k; ++j)
            if(lev[lca[i-1][j]]<lev[lca[i-1][j+p[i-1]]])
                lca[i][j]=lca[i-1][j];
            else
                lca[i][j]=lca[i-1][j+p[i-1]];
    }

    int sz = log(n);

    for(i=1; i<=sz; ++i)
    {
        for(j=1; j<=n; ++j)
            father[i][j]=father[i-1][father[i-1][j]];
    }

    for(i=1; i<=sz; ++i)
    {
        for(j=1; j<=n; ++j)
            cst[i][j]=max(cst[i-1][j],cst[i-1][father[i-1][j]]);
    }

    while(q--)
    {
        int x,y;
        fin>>x>>y;
        if(poz[x]>poz[y])
            swap(x,y);
        int d = poz[y]-poz[x]+1;
        d = log(d);
        int l = min(lev[lca[d][poz[x]]],lev[lca[d][poz[y]-p[d]+1]]);
        int ans1 = 0, d1 = lev[x] - l;
        while(d1)
        {
            int c = log(d1);
            ans1 = max(ans1,cst[c][x]);
            x = father[c][x];
            d1-=p[c];
        }
        int ans2 = 0, d2 = lev[y] - l;
        while(d2)
        {
            int c = log(d2);
            ans2 = max(ans2,cst[c][y]);
            y = father[c][y];
            d2-=p[c];
        }
        fout<<max(ans1,ans2)<<'\n';
    }

}
