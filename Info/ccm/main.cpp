#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream fin("ccm.in");
ofstream fout("ccm.out");

const int modulo = 9901;

inline int mod(int x)
{
    if(x>=modulo)
        return x%modulo;
    return x;
}

vector <int> v[17];
int l[17];
int r[17];
int p[17];
int viz[17];
int d[1<<17][17];
int ans[1<<17][17];
int i,j,k,n,m,q;

int main()
{
    fin>>n>>m>>q;
    p[0]=1;
    for(i=1; i<=m; ++i)
        p[i]=p[i-1]*2;
    int x,y,ok;
    while(q--)
    {
        fin>>x>>y;
        v[x].push_back(y);
    }
    int lim = (1<<m);
    for(j=0; j<lim; ++j)
        ans[j][0]=1;
    for(i=0; i<=n; ++i)
        ans[0][i]=1;
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<lim; ++j)
        {
            d[j][i]=d[j][i-1];
            for(auto it:v[i])
                if(p[it-1]&j)
                    d[j][i]=max(d[j][i],d[p[it-1]^j][i-1]+1);

            if(d[j][i]==d[j][i-1])
                ans[j][i]=ans[j][i-1];
            for(auto it:v[i])
                if(p[it-1]&j)
                {
                    d[j][i]=max(d[j][i],d[p[it-1]^j][i-1]+1);
                    if(d[j][i]==d[p[it-1]^j][i-1]+1)
                        ans[j][i]+=ans[p[it-1]^j][i-1];
                }
            ans[j][i]=mod(ans[j][i]);
        }
    }
    fout<<d[p[m]-1][n]<<' '<<ans[p[m]-1][n];
}
