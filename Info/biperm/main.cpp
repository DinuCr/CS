#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("biperm.in");
ofstream fout("biperm.out");

#define mp make_pair
#define f first
#define s second

struct nod
{
    int x,i,d;
};

int viz[10010];
int v[10010];
int w[10010];
vector <nod> g[10010];
int ans,nr,change,sz,n,i,start;

long long po(int x,int y)
{
    if(y==0)
        return 1;
    return x*po(x,y-1);
}

void df(int x)
{
    ++sz;
    viz[x]=1;
    for(int i=0; i<g[x].size(); ++i)
    {
        if(!viz[g[x][i].x])
        {
            if(g[x][i].d==1)
            {
                ++change;
                swap(v[g[x][i].i],w[g[x][i].i]);
            }
            nod y = g[x][i];
            swap(g[x][i],g[x][g[x].size()-1]);
            g[x].pop_back();
            if(g[y.x][0].x==x && g[y.x][0].d==!y.d)
            {
                swap(g[y.x][0],g[y.x][g[y.x].size()-1]);
                g[y.x].pop_back();
            }
            else
                g[y.x].pop_back();
            df(y.x);
            return;
        }
    }
    for(int i=0; i<g[x].size(); ++i)
    {
        if(g[x][i].x==start)
            if(g[x][i].d==1)
            {
                ++change;
                swap(v[g[x][i].i],w[g[x][i].i]);
            }
        return;
    }

}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    for(i=1; i<=n; ++i)
        fin>>w[i];
    for(i=1; i<=n; ++i)
    {
        nod x;
        x.x=w[i];
        x.i=i;
        x.d=1;
        g[v[i]].push_back(x);
        x.d=0;
        x.x=v[i];
        g[w[i]].push_back(x);
    }
    for(i=1; i<=n; ++i)
        if(!viz[i])
        {
            sz=0;
            change=0;
            start=i;
            df(i);
            if(sz>1)
                ++nr;
            ans+=min(change,sz-change);
        }
    fout<<po(2*1LL,nr*1LL)<<' '<<ans<<'\n';
    for(i=1; i<=n; ++i)
        fout<<v[i]<<' ';
    fout<<'\n';
    for(i=1; i<=n; ++i)
        fout<<w[i]<<' ';
}
