#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("snowball.in");
ofstream fout("snowball.out");

#define nmax 500100

int last[nmax];
int v[nmax];
int f[10010];
int b[10010];
int i,n,m;

int main()
{
    fin>>m>>n;
    for(i=1; i<=m; ++i)
    {
        fin>>b[i];
        f[b[i]]=i;
        last[i]=n+1;
    }
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
    }
    int mx = 0;
    long long ans = 0;
    int dr=n+1;
    for(i=n; i>0; --i)
    {
        if(f[v[i]]==m)
            last[m]=i;
        else
        if(f[v[i]]>1)
            last[f[v[i]]]=last[f[v[i]]+1];
        else
        if(f[v[i]]==1)
            dr=last[f[v[i]]+1];
        ans+=dr-i;
        mx=max(mx,dr-i);
    }
    fout<<mx<<' '<<ans;
}
