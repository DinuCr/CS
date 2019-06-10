#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int ind[100100];
int n,x,ans,j,i;

int main()
{
    freopen("sum.in","r",stdin);
    scanf("%d",&n);
    for(i=1; i<=100000; ++i)
        ind[i]=i;
    for(j=2; j<=100000; j+=2)
        ind[j]=ind[j]/2;
    for(i=3; i<=100000; i+=2)
        if(ind[i]==i)
        {
            for(j=i; j<=100000; j+=i)
                ind[j]=ind[j]/i*(i-1);
        }
    freopen("sum.out","w",stdout);
    while(n--)
    {
        scanf("%d",&x);
        printf("%lld\n",(long long)2*ind[x]*x);
    }
}
