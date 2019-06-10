#include <cstdio>

using namespace std;

long long i,j,n,a,b,k,s;
long long m[500100],d[500100];

int main()
{
    freopen("divk.in","r",stdin);
    freopen("divk.out","w",stdout);

    scanf("%d%d%d%d",&n,&k,&a,&b);

    int x;

    for(i=1; i<=n; ++i)
    {
        scanf("%d",&x);
        m[i]=(m[i-1]+x)%k;
    }

    for(i=a; i<=n; ++i)
    {
        d[m[i-a]]++;
        if(i>b)
            d[m[i-b-1]]--;
        s+=d[m[i]];
    }
    printf("%lld",s);
}
