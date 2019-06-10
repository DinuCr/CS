#include <cstdio>

using namespace std;
int i,j,a,v[20],n,k,d[1010][3];

int main()
{
    freopen("div3.in","r",stdin);
    freopen("div3.out","w",stdout);

    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&v[i]);
        d[1][v[i]%3]++;
    }
    for(i=1; i<=k; ++i)
        for(j=0; j<3; ++j)
            for(a=1; a<=n; ++a)
            {
                d[i][(j+v[a])%3]+=d[i-1][j];
                d[i][(j+v[a])%3]%=4001;
            }
    printf("%d",d[k][0]);
}
