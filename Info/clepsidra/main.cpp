#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("clepsidra.in");
ofstream fout("clepsidra.out");

const int mod = 666013;

#define nmax 200010

vector <int> v[nmax];
int ans[nmax];
int w[nmax];
int last[nmax];
int dfn[nmax];
int low[nmax];
int n,m,k,nr;

void df(int x,int t)
{
    dfn[x]=low[x]=++k;
    if(t)
        ++w[x];
    for(auto it:v[x])
        if(it!=t)
        {
            if(dfn[it])
            {
                low[x]=min(low[x],dfn[it]);
            }
            else
            {
                df(it,x);
                low[x]=min(low[x],low[it]);
                if(low[it]>=dfn[x])
                    ++w[x];
            }
        }
}

inline int modulo(long long x)
{
    if(x>=mod)
        return x%mod;
    return x;
}

long long exp(long long a,int b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b&1)
        return modulo(1LL*exp(a,b-1)*a);
    return modulo(exp(modulo(a*a*1LL),b>>1));
}

int main()
{
    int i;
    fin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        int a,b;
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    df(1,0);
    for(i=1; i<=n; ++i)
        fout<<modulo(exp(2,w[i])-2+mod)<<'\n';
}
