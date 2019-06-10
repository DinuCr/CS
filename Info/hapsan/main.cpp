#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("hapsan.in");
ofstream fout("hapsan.out");

#define nmax 200010
#define zeros(x) x&(-x)

int v[nmax];
int aib[nmax];
int w[nmax];
int d[nmax];
vector <int> out[nmax];
int n;

int update(int poz,int x)
{
    for( ; poz<=n; poz+=zeros(poz))
        aib[poz]=max(aib[poz],x);
}

int compute(int poz)
{
    int ans = 0;
    for( ; poz; poz-=zeros(poz))
        ans=max(ans,aib[poz]);
    return ans;
}

int main()
{
    int i,m,a,b;
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    fin>>m;
    for(i=1; i<=m; ++i)
    {
        fin>>a>>b;
        out[b].push_back(a);
        w[a]++;
    }
    int p = 1;
    int ans = 0;
    for(i=1; i<=n; ++i)
    {
        for(auto it:out[i-1])
            --w[it];
        for( ;!w[p] && p<i; ++p)
            update(v[p],d[p]);
        d[i]=compute(v[i]-1)+v[i];
        ans=max(ans,d[i]);
    }
    fout<<ans;
}
