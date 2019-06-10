#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("hektor.in");
ofstream fout("hektor.out");

#define nmax 100100

vector <int> v[nmax];
vector <int> g[nmax];
double d[nmax];
int viz1[nmax];
int viz2[nmax];
int viz[nmax];
int used[nmax];
int a,b,n,m,i;

void df1(int x)
{
    for(auto it:v[x])
    {
        if(viz1[it])
            continue;
        viz1[it]=1;
        df1(it);
    }
}

void df2(int x)
{
    for(auto it:g[x])
    {
        if(viz2[it])
            continue;
        viz2[it]=1;
        df2(it);
    }
}

void compute(int x)
{
    if(x==b)
        return;
    double s=0;
    double nr=0;
    for(auto it:v[x])
    {
        if(!viz[it])
            continue;
        nr++;
        if(!used[it])
        {
            used[it]=1;
            compute(it);
        }
        s+=d[it];
    }
    d[x]+=(double)s/nr;
}

int main()
{
    fin>>n>>m>>a>>b;
    for(i=1; i<=n; ++i)
        fin>>d[i];
    for(i=1; i<=m; ++i)
    {
        int x,y;
        fin>>x>>y;
        v[x].push_back(y);
        g[y].push_back(x);
    }
    viz1[a]=viz2[b]=1;
    df1(a);
    df2(b);

    for(i=1; i<=n; ++i)
        viz[i]=viz1[i]&viz2[i];

    used[a]=1;
    compute(a);

    fout<<setprecision(10)<<fixed<<d[a];
}
