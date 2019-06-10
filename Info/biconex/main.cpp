#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("biconex.in");
ofstream fout("biconex.out");

#define nmax 100100
#define mp make_pair
#define f first
#define s second

stack <pair <int,int> > q;
vector <int> v[nmax];
vector <vector <int> > ans;
int dfn[nmax];
int low[nmax];
int added[nmax];
int n,nr,i,nrcomp,m;

void add(int x,int y)
{
    vector <int> curr;
    nrcomp++;
    int a,b;
    added[x]=added[y]=nrcomp;
    curr.push_back(x);
    curr.push_back(y);
    while(q.top().f!=x || q.top().s!=y)
    {
        a=q.top().f;
        b=q.top().s;
        q.pop();
        if(added[a]!=nrcomp)
        {
            curr.push_back(a);
            added[a]=nrcomp;
        }
        if(added[b]!=nrcomp)
        {
            curr.push_back(b);
            added[b]=nrcomp;
        }
    }
    q.pop();
    ans.push_back(curr);
}

void df(int x,int t)
{
    dfn[x]=low[x]=++nr;
    for(int i=0; i<v[x].size(); ++i)
    if(v[x][i]!=t)
    {
        if(!dfn[v[x][i]])
        {
            q.push(mp(x,v[x][i]));
            df(v[x][i],x);
            low[x]=min(low[x],low[v[x][i]]);
            if(low[v[x][i]]>=dfn[x])
                add(x,v[x][i]);
        }
        else
            low[x]=min(low[x],dfn[v[x][i]]);
    }
}

int main()
{
    fin>>n>>m;
    int x,y;
    for(i=1; i<=m; ++i)
    {
        fin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    df(1,0);
    fout<<ans.size()<<'\n';
    for(i=0; i<ans.size(); ++i)
    {
        for(int j=0; j<ans[i].size(); ++j)
            fout<<ans[i][j]<<' ';
        fout<<'\n';
    }
}
