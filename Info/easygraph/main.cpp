#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("easygraph.in");
ofstream fout("easygraph.out");

#define nmax 16000

vector <long long> v[nmax];
long long c[nmax];
long long ans[nmax];
long long viz[nmax];
long long n,m,i,a,b,mx,t;

void df(long long x)
{
    if(!viz[x])
    {
        viz[x]=1;
        for(long long i=0; i<v[x].size(); ++i)
            df(v[x][i]);
        long long mx1 = 0;
        for(long long i=0; i<v[x].size(); ++i)
            mx1=max(mx1,ans[v[x][i]]);
        ans[x]=mx1+c[x];
        mx=max(ans[x],mx);
    }
}

int main()
{
    fin>>t;
    while(t--)
    {
        fin>>n>>m;
        for(i=1; i<=n; ++i)
            fin>>c[i];
        for(i=1; i<=m; ++i)
        {
            fin>>a>>b;
            v[a].push_back(b);
        }
        mx=-100000000000000;
        for(i=1; i<=n; ++i)
            if(!viz[i])
                df(i);
        fout<<mx<<'\n';
        for(i=1; i<=n; ++i)
        {
            ans[i]=viz[i]=0;
            v[i].clear();
        }
    }
}
