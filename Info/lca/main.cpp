#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream f("lca.in");
ofstream g("lca.out");

vector <int> v[100010];

int lev[250010], e[250010], poz[100010], p[25];

int n,i,k,m,x,j,a,b,d;

int rmq[20][250010];

void dfe(int x, int l)
{
    ++n;
    lev[n]=l;
    e[n]=x;
    poz[x]=n;

    for(int i=0; i<v[x].size(); ++i)
    {
        dfe(v[x][i],l+1);
        ++n;
        e[n]=x;
        lev[n]=l;
    }
}

inline int log(int x)
{
    int i=0;
    while(p[i+1]<x)
        ++i;
    return i;
}

int main()
{
    f>>n>>m;
    for(i=2; i<=n; ++i)
    {
        f>>x;
        v[x].push_back(i);
    }

    p[0]=1;
    for(i=1; i<20; ++i)
        p[i]=p[i-1]*2;

    n=0;
    dfe(1,0);

    for(i=1; i<=n; ++i)
        rmq[0][i]=i;

    k=log(n)+1;
    for(i=1; i<k; ++i)
    {
        for(j=1; j<=n; ++j)
        {
            if(lev[rmq[i-1][j+p[i-1]]]<lev[rmq[i-1][j]])
                rmq[i][j]=rmq[i-1][j+p[i-1]];
            else
                rmq[i][j]=rmq[i-1][j];
        }
    }

    for(i=1; i<=m; ++i)
    {
        f>>a>>b;
        a=poz[a];
        b=poz[b];
        if(a>b)
            swap(a,b);

        d=b-a+1;
        k=log(d);

        if(lev[rmq[k][a]]<lev[rmq[k][b-p[k]+1]])
                g<<e[rmq[k][a]]<<'\n';
            else
                g<<e[rmq[k][b-p[k]+1]]<<'\n';
    }
}
