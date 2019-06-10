#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("pm2.in");
ofstream fout("pm2.out");

#define nmax 110

vector <int> v[nmax];
vector <int> g[nmax];
int d1[nmax];
int d2[nmax];
int w[nmax];
int c[nmax];
int viz[nmax];
int n,k,m,j;

void df(int x)
{
    viz[x]=1;
    for(auto it:v[x])
        if(!viz[it])
            df(it);
    w[++k]=x;
}

int main()
{
    int i;
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>c[i];
    for(i=1; i<=n; ++i)
    {
        fin>>m;
        int x;
        for(j=1; j<=m; ++j)
        {
            fin>>x;
            v[i].push_back(x);
            g[x].push_back(i);
        }
    }
    for(i=1; i<=n; ++i)
        if(!viz[i])
            df(i);
    int ans = 0;
    for(i=1; i<=n; ++i)
    {
        for(auto it:v[w[i]])
            d1[w[i]]=max(d1[w[i]],d1[it]+c[w[i]]);
        if(!v[w[i]].size())
            d1[w[i]]=c[w[i]];
        if(!g[w[i]].size())
            ans=max(ans,d1[w[i]]);
    }
    fout<<ans<<'\n';
    for(i=n; i>0; --i)
    {
        d2[w[i]]=1e9;
        for(auto it:g[w[i]])
            d2[w[i]]=min(d2[w[i]],d2[it]-c[w[i]]);
        if(!g[w[i]].size())
            d2[w[i]]=ans-c[w[i]];
    }
    for(i=1; i<=n; ++i)
        fout<<d1[i]-c[i]<<' '<<d2[i]<<'\n';

}
