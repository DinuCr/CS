#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

ifstream fin("cartite.in");
ofstream fout("cartite.out");

#define nmax 210
#define mp make_pair
#define f first
#define s second

int v[nmax][nmax];
vector <int> g[nmax*nmax];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m,a,b,k,p,x,y,z,i,t;

void sterge(int x,int y)
{
    for(int i=0; i<g[x].size(); ++i)
        if(g[x][i]==y)
        {
            swap(g[x][i],g[x][g[x].size()-1]);
            g[x].pop_back();
            return ;
        }
}

void euler(int x)
{
    while(g[x].size())
    {
        int nod = g[x].back();
        g[x].pop_back();
        sterge(nod,x);
        euler(nod);
    }
    fout<<(x-1)/m+1<<' '<<(x%m==0?m:x%m)<<'\n';
}

int main()
{
    fin>>p>>n>>m>>a>>b>>k;
    for(i=1; i<=k; ++i)
    {
        fin>>x>>y>>z;
        v[x][y]=-1;
        if(z>0)
        {
            v[x-1][y]=v[x+1][y]=v[x][y-1]=v[x][y+1]=-1;
        }
        if(z>1)
        {
            v[max(x-2,0)][y]=v[x-1][y+1]=v[x-1][y-1]=v[x][max(0,y-2)]=v[x][y+2]=v[x+1][y+1]=v[x+1][y-1]=v[x+2][y]=-1;
        }
    }
    for(i=1; i<=n; ++i)
        v[i][0]=v[i][m+1]=-1;
    for(i=1; i<=m; ++i)
        v[n+1][i]=v[0][i]=-1;
    fin>>k;
    for(i=1; i<=k; ++i)
    {
        fin>>x>>y>>z>>t;
        if(v[x][y]==0)
            v[x][y]=-2;
        if(v[z][t]==0)
            v[z][t]=-2;
        g[(x-1)*m+y].push_back((z-1)*m+t);
        g[(z-1)*m+t].push_back((x-1)*m+y);
    }
    if(p==1)
    {
        queue <pair<int,int> > q;
        q.push(mp(a,b));
        if(v[a][b]==-2)
        {
            fout<<a<<' '<<b<<' '<<0;
            exit(0);
        }
        v[a][b]=1;
        while(!q.empty())
        {
            a = q.front().f;
            b = q.front().s;
            q.pop();
            for(k=0; k<4; ++k)
                if(v[a+dx[k]][b+dy[k]]==0)
                {
                    v[a+dx[k]][b+dy[k]]=v[a][b]+1;
                    q.push(mp(a+dx[k],b+dy[k]));
                }
                else
                if(v[a+dx[k]][b+dy[k]]==-2)
                {
                    fout<<a+dx[k]<<' '<<b+dy[k]<<' '<<v[a][b];
                    exit(0);
                }
        }
    }
    else
        euler((x-1)*m+y);
}
