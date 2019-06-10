#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream fin("arbxyz.in");
ofstream fout("arbxyz.out");

#define pb push_back

vector <int> v[100010];
int w[100010];
int last[100010];
int viz[100010];
int first_y[100010];
int last_y[100010];
int n,k,ans,ok,x,y,z,q[5],t,i;

void df(int x)
{
    viz[x]=1;
    w[++k]=x;
    for(auto it:v[x])
        if(!viz[it])
        {
            df(it);
        }
    last[x]=k;
}

void compute()
{
    memset(last_y, 0, sizeof(last_y));
    memset(first_y, 0, sizeof(first_y));

    for(int i=n; i>0; --i)
    {
        if(last[w[i]]-i+1==y)
        {
            first_y[i]=i;
            last_y[i]=max(last_y[i+1],i);
        }
        else
        {
            first_y[i]=first_y[i+1];
            last_y[i]=last_y[i+1];
        }
    }
    for(int i=1; i<=n; ++i)
    {
        if(last[w[i]]-i+1==x && last_y[i]>last[w[i]] && last_y[i]!=0)
        {
            ans=1;
            return;
        }
        if(last[w[i]]-i+1==x+y && first_y[i]<=last[w[i]] && first_y[i]!=0)
        {
            ans=1;
            return;
        }
    }
}

int main()
{
    fin>>t;
    while(t--)
    {
        fin>>n>>q[1]>>q[2]>>q[3];
        for(i=1; i<=n; ++i)
            v[i].clear();
        memset(viz, 0, sizeof(viz));
        for(i=1; i<n; ++i)
        {
            int a,b;
            fin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        k=0;
        df(1);
        sort(q+1,q+4);
        ok = 1;
        ans = 0;
        for( ; ok; ok=next_permutation(q+1,q+4))
        {
            x=q[1];
            y=q[2];
            z=q[3];
            compute();
            if(ans)
            {
                fout<<ans<<'\n';
                break;
            }
        }
        if(!ans)
            fout<<ans<<'\n';
    }
}
