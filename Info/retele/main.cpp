#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define nmax 50100

ifstream fin("retele.in");
ofstream fout("retele.out");

vector <int> v[nmax];
vector <int> w[nmax];
vector <int> ans[nmax];
int vis[nmax];
int t[nmax];
int ord[nmax];
int n,m,k,a,b,i,j;

void dfs(int n)
{
    vis[n]=1;
    for(int i=0; i<v[n].size(); ++i)
        if(!vis[v[n][i]])
            dfs(v[n][i]);
    t[++k]=n;
}

void dfst(int n)
{
    vis[n]=-1;
    ans[k].pb(n);
    for(int i=0; i<w[n].size(); ++i)
        if(vis[w[n][i]]==1)
            dfst(w[n][i]);
}

int main()
{
    fin>>n>>m;

    for(i=0; i<m; ++i)
    {
        fin>>a>>b;
        v[a].pb(b);
        w[b].pb(a);
    }

    k=0;
    for(i=1; i<=n; ++i)
        if(!vis[i])
            dfs(i);
    k=0;
    for(i=n; i>0; --i)
        if(vis[t[i]]==1)
        {
            ++k;
            dfst(t[i]);
            sort(ans[k].begin(), ans[k].end());
            ord[ans[k][0]]=k;
        }
    fout<<k<<'\n';
    for(i=1; i<=n; ++i)
    if(ord[i]!=0)
    {
        fout<<ans[ord[i]].size()<<' ';
        for(j=0; j<ans[ord[i]].size(); ++j)
            fout<<ans[ord[i]][j]<<' ';
        fout<<'\n';
    }
}
