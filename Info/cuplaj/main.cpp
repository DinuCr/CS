#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream fin("cuplaj.in");
ofstream fout("cuplaj.out");

#define nmax 10010

vector <int> v[nmax];
int viz[nmax];
int l[nmax];
int r[nmax];
int n,m,q,i;

bool pairup(int x)
{
    if(viz[x])
        return 0;
    viz[x]=1;
    for(auto it:v[x])
        if(!r[it])
        {
            l[x]=it;
            r[it]=x;
            return 1;
        }
    for(auto it:v[x])
        if(pairup(r[it]))
        {
            l[x]=it;
            r[it]=x;
            return 1;
        }
    return 0;
}

int main()
{
    fin>>n>>m>>q;
    int x,y;
    for(i=1; i<=q; ++i)
    {
        fin>>x>>y;
        v[x].push_back(y);
    }
    int ok=1;
    while(ok)
    {
        ok=0;
        memset(viz, 0, sizeof(viz));
        for(i=1; i<=n; ++i)
            if(!l[i])
                ok|=pairup(i);
    }
    int ans = 0;
    for(i=1; i<=n; ++i)
        ans+=(bool)(l[i]);
    fout<<ans<<'\n';
    for(i=1; i<=n; ++i)
        if(l[i])
            fout<<i<<' '<<l[i]<<'\n';
}
