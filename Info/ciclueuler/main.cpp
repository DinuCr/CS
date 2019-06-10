#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define pb push_back

vector <int> v[100001];
int st[500010];
int cn[500010];
int n,m,k;

void sterge(int x,int y)
{
    int i;
    for(i=0; i<v[x].size(); ++i)
        if(v[x][i]==y)
        {
            swap(v[x][i],v[x][v[x].size()-1]);
            v[x].pop_back();
            return ;
        }
}

void euler()
{
    int x;
    while(k>0)
    {
        if(v[st[k]].size()>0)
        {
            x=v[st[k]][0];
            sterge(st[k],x);
            sterge(x,st[k]);

            st[++k]=x;
        }
        else
        {
            --k;
            if(k)
                printf("%d ",st[k]);
        }
    }
}

int main()
{
    freopen("ciclueuler.in","r",stdin);
    freopen("ciclueuler.out","w",stdout);

    int i,a,b;

    scanf("%d%d",&n,&m);

    for(i=0; i<m; ++i)
    {
        scanf("%d%d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }

    int ok=1;
    for(i=1; i<=n; ++i)
        if(v[i].size()%2==1)
        {
            ok=0;
            printf("-1");
            break;
        }

    k=1;
    st[k]=1;

    if(ok)
        euler();
}
