#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[16010];
int mx,t[16010],c[16010],n;

int df(int x)
{
    int i,s=c[x],a;
    for(i=0; i<v[x].size(); ++i)
    if(v[x][i]!=t[x])
    {
        t[v[x][i]]=x;
        a=df(v[x][i]);
        if(a>0)
            s+=a;
    }
    mx=max(mx,s);
    return s;
}

int main()
{
    freopen("asmax.in","r",stdin);
    freopen("asmax.out","w",stdout);
    scanf("%d",&n);
    int i;
    for(i=1; i<=n; ++i)
        scanf("%d",&c[i]);
    int a,b;
    for(i=1; i<n; ++i)
    {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    mx=-160000000;
    mx=max(mx,df(1));
    printf("%d",mx);
}
