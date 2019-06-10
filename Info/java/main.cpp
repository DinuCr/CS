#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream fin("java.in");
ofstream fout("java.out");

#define nmax 10010

vector <int> v[nmax];
int viz[nmax];
int l[nmax];
int r[nmax];
int n,m,i,q,t;

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
    fin>>t;
    while(t--)
    {
        fin>>n>>m>>q;
        int x,y;
        while(q--)
        {
            fin>>x>>y;
            v[x].push_back(y);
        }
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));


        int ok=1,ans=0;
        while(ok)
        {
            ok=0;
            memset(viz, 0, sizeof(viz));
            for(i=1; i<=n; ++i)
                if(!l[i])
                    ok|=pairup(i);
        }
        for(i=1; i<=n; ++i)
        {
            ans+=(l[i]>0);
            v[i].clear();
        }
        fout<<ans<<'\n';
    }
}
