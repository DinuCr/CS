#include <cstdio>
#include <iostream>
using namespace std;

int d[1010][1010],r[1010];

int main()
{
    freopen("custi.in","r",stdin);
    freopen("custi.out","w",stdout);
    int j,i,n;
    scanf("%d",&n);
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
        {
            scanf("%d",&d[i][j]);
            if(d[i][j]==1)
            d[i][j]=min(d[i-1][j],min(d[i][j-1],d[i-1][j-1]))+1;
        }
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            ++r[d[i][j]];
    for(i=n; i>0; --i)
        r[i]+=r[i+1];
    for(i=1; i<=n; ++i)
        printf("%d\n",r[i]);
}
