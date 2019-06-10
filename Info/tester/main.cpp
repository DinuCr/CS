#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define f first
#define s second

pair <int,int> v[5100];
vector <int> g[5100];
int in[5100];
int out[5100];
int st[5100000];
int ans[5100000];
int n,m,k,z;

int main()
{
    freopen("tester.in","r",stdin);
    freopen("tester.out","w",stdout);
    scanf("%d%d",&n,&m);
    int a,b;
    int i,j;
    for(i=1; i<=m; ++i)
    {
        scanf("%d%d",&a,&b);
        v[i]=make_pair(a,b);
    }
    for(i=1; i<=m; ++i)
        for(j=1; j<=m; ++j)
            if(i!=j)
            {
                if(v[i].s==v[j].f)
                {
                    ++in[j];
                    ++out[i];
                    g[i].push_back(j);
                }
            }
    for(i=1; i<=m; ++i)
        {
            for(j=in[i]; j<out[i]; ++j)
                g[0].push_back(i);
            for(j=out[i]; j<in[i]; ++j)
                g[i].push_back(0);
        }

    k=1;
    st[k]=0;
    int x;
    while(k>0)
    {
        if(!g[st[k]].empty())
        {
            x = g[st[k]][g[st[k]].size()-1];
            g[st[k]].pop_back();

            st[++k]=x;
        }
        else
            ans[++z]=st[k--];
    }

    for(i=z-1; i>1; --i)
    {
        if(!ans[i])
            printf("R ");
        else
        if(v[ans[i+1]].s==v[ans[i]].f)
            printf("%d ",v[ans[i]].s);
        else
            printf("%d %d ",v[ans[i]].f,v[ans[i]].s);
    }
}
