#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream fin("pang.in");
ofstream fout("pang.out");

#define nmax 100010

vector <int> v[nmax];
int d[nmax];
int w[nmax];

void df(int x)
{
    d[x]=w[x]+1;
    for(auto it:v[x])
    {
        if(!d[it])
            df(it);
        d[x]=max(d[x],d[it]+w[x]);
    }
}

int main()
{
    int t;
    fin>>t;
    while(t--)
    {
        int a,b,n,m,k,i;
        memset(d, 0, sizeof(d));
        memset(w, 0, sizeof(w));
        fin>>n>>m>>k;
        while(m--)
        {
            fin>>a>>b;
            v[b].push_back(a);
        }
        for(i=1; i<=k; ++i)
        {
            fin>>a;
            w[a]=1;
        }
        for(i=1; i<=n; ++i)
            if(!d[i])
                df(i);
        int ok=0;
        for(i=1; i<=n; ++i)
            if(d[i]==k+1)
            {
                ok=i;
                break;
            }
        if(!ok)
            fout<<"Nu\n";
        else
        {
            fout<<"Da\n";
            vector <int> ans;
            while(d[ok]-w[ok]!=1)
            {
                for(auto it:v[ok])
                    if(d[it]==d[ok]-w[ok])
                    {
                        if(w[ok])
                            ans.push_back(ok);
                        ok=it;
                        break;
                    }
            }
            if(w[ok])
                ans.push_back(ok);
            while(ans.size())
                fout<<ans.back()<<' ',ans.pop_back();
            fout<<'\n';
        }
        for(i=1; i<=n; ++i)
            v[i].clear();
    }
}
