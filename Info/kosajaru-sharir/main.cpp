#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define nmax 100100

ifstream fin("ctc.in");
ofstream fout("ctc.out");

vector <int> v[nmax];
vector <int> vt[nmax];
vector <int> comp[nmax];
int t[nmax];
int viz[nmax];
int n,m,a,b,i,k;

void dfs(int x)
{
    viz[x]=1;
    for(int i=0; i<v[x].size(); ++i)
        if(viz[v[x][i]]==0)
            dfs(v[x][i]);
    t[++k]=x;
}

void dfst(int x)
{
    viz[x]=-1;
    comp[a].push_back(x);
    for(int i=0; i<vt[x].size(); ++i)
        if(viz[vt[x][i]]==1)
            dfst(vt[x][i]);
}


int main()
{
    fin>>n>>m;
    for(i=1; i<=m; ++i)
        {
            fin>>a>>b;
            v[a].push_back(b);
            vt[b].push_back(a);
        }
    for(i=1; i<=n; ++i)
        if(viz[i]==0)
            {
                dfs(i);
            }
    a=0;
    for(i=n; i>0; --i)
        if(viz[t[i]]!=-1)
        {
            a++;
            dfst(t[i]);
        }
    fout<<a<<'\n';
    for(i=1; i<=a; ++i)
    {
        for(int j=0; j<comp[i].size(); ++j)
            fout<<comp[i][j]<<' ';
        fout<<'\n';
    }
}
