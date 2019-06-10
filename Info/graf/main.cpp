#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

#define nmax 7600

ifstream fin("graf.in");
ofstream fout("graf.out");

vector <int> v[nmax];
queue <int> q;
int dr[nmax];
int ans[nmax];
bool viz[nmax];
int n,m,a,b,x,y,i;

int main()
{
    fin>>n>>m>>x>>y;
    for(i=1; i<=m; ++i)
    {
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    q.push(x);
    for(i=1; i<=n; ++i)
        dr[i]=1000000;
    dr[x]=0;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(i=0; i<v[a].size(); ++i)
            if(dr[v[a][i]]>dr[a]+1)
            {
                dr[v[a][i]]=dr[a]+1;
                q.push(v[a][i]);
            }
    }
    q.push(y);
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        viz[a]=1;
        if(ans[dr[a]]==0)
            ans[dr[a]]=a;
        else
        if(ans[dr[a]]!=a)
            ans[dr[a]]=-1;
        for(i=0; i<v[a].size(); ++i)
        {
            b=v[a][i];
            if(dr[v[a][i]]==dr[a]-1 && ans[dr[v[a][i]]]==0 && viz[v[a][i]]==0)
            {
                q.push(v[a][i]);
                viz[v[a][i]]=1;
            }
        }
    }
    for(i=1; i<=n; ++i)
        cout<<i<<' '<<dr[i]<<'\n';
    int nr=0;
    for(i=1; i<=n; ++i)
        dr[i]=0;
    for(i=0; i<=n; ++i)
        if(ans[i]>0)
        {
            ++nr;
            dr[ans[i]]=1;
        }
    fout<<nr<<'\n';
    for(i=1; i<=n; ++i)
        if(dr[i])
            fout<<i<<' ';
}
