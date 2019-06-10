#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cerere.in");
ofstream fout("cerere.out");

vector <int> g[100100];
int t[100100];
int sol[100100];
int v[100100];
int st[100100];
int a,b,i,j,k,n,r;

void dfs(int x)
{
    st[++k]=x;
    if(v[x]==0)
        sol[x]=0;
    else
        sol[x]=sol[st[k-v[x]]]+1;
    for(int i=0; i<g[x].size(); ++i)
        dfs(g[x][i]);
    --k;
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    for(i=1; i<n; ++i)
    {
        fin>>a>>b;
        g[a].push_back(b);
        t[b]=a;
    }
    for(i=1; i<=n; ++i)
        if(t[i]==0)
            r=i;
    dfs(r);
    for(i=1; i<=n; ++i)
        fout<<sol[i]<<' ';
}
