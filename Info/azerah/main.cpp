#include <cstdio>

using namespace std;

const int mod=1000000007;

int po(int x,int y)
{
    if (y <= 0) return 1;
    if(y==1)
        return x;
    if(y%2==0)
        return (po((1LL*x*x)%mod,(y>>1)))%mod;
    return (1LL*x*po(x,y-1))%mod;
}
int main()
{
    freopen("azerah.in","r",stdin);
    freopen("azerah.out","w",stdout);
    int n,nrp,nri,x;
    int t,k,i;
    int s;
    scanf("%d",&t);
    for( k=0 ; k<t ; ++ k )
    {
        scanf("%d",&n);
        nrp=nri=0;
        for( i=0 ; i<n ; ++ i )
        {
            scanf("%d",&x);
            if(x%2==1)
                ++nri;
            else
                ++nrp;
        }
        s=(1LL * po(2,nrp)* po(2,nri-1)) % mod;
        s--;
        s=(s+mod)%mod;
        printf("%d\n",s);
    }
}
