#include <iostream>
#include <cstdio>
using namespace std;
int ls,ld,v[200100],d[200100],n,m,x,i;
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        if(v[i]==v[i-1])
            d[i]=d[i-1]+1;
        else
            d[i]=1;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&ls,&ld,&x);
        if(v[ld]!=x)
        printf("%d\n",ld);
        else
        if(d[ld]-d[ls]==ld-ls)
        printf("-1\n");
        else
        printf("%d\n",ld-d[ld]);
    }
}
