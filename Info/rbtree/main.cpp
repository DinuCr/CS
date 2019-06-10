#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("rbtree.in");
ofstream fout("rbtree.out");

#define nmax 100010

vector <int> v[nmax];
vector <int> g[nmax];
int dr[nmax];
int dn[nmax];
int d[nmax];
int col[nmax];
int n,r,b,i;

void bfgigel()
{
    queue <int> q;
    for(i=1; i<=n; ++i)
        d[i]=nmax;
    q.push(1);
    d[1]=0;
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        for(auto it:v[nod])
            if(d[nod]+1<d[it])
            {
                d[it]=d[nod]+1;
                q.push(it);
            }
    }
}

void bfnegru()
{
    queue <int> q;
    for(i=1; i<=n; ++i)
        if(col[i]!=2)
        {
            dn[i]=nmax;
        }
        else
        {
            dn[i]=0;
            q.push(i);
        }
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        for(auto it:g[nod])
            if(dn[nod]+1<dn[it])
            {
                dn[it]=dn[nod]+1;
                q.push(it);
            }
    }
}

void bfrosu()
{
    queue <int> q;
    for(i=1; i<=n; ++i)
        if(col[i]!=1)
        {
            dr[i]=nmax;
        }
        else
        {
            dr[i]=0;
            q.push(i);
        }
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        for(auto it:g[nod])
            if(dr[nod]+1<dr[it])
            {
                dr[it]=dr[nod]+1;
                q.push(it);
            }
    }
}

int main()
{
    fin>>n>>r>>b;
    int x,a;
    for(i=1; i<=r; ++i)
    {
        fin>>x;
        col[x]=1;
    }
    for(i=1; i<=b; ++i)
    {
        fin>>x;
        col[x]=2;
    }
    for(i=1; i<=n; ++i)
    {
        fin>>x;
        while(x--)
        {
            fin>>a;
            v[i].push_back(a);
            g[a].push_back(i);
        }
    }
    bfgigel();
    bfnegru();
    bfrosu();
    int ans = 100*nmax;
    for(i=1; i<=n; ++i)
        if(d[i]!=nmax && dn[i]!=nmax && dr[i]!=nmax)
            ans=min(ans,d[i]+dn[i]+dr[i]);
    if(ans!=100*nmax)
        fout<<ans;
    else
        fout<<"impossible";
}
