#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("farfurii.in","r",stdin);
    freopen("farfurii.out","w",stdout);

    long long n,k,i,j,p;
    scanf("%lld%lld",&n,&k);
    for(i=1; i<=n; ++i)
        if((i-1)*i/2>=k)
            break;
    p=i;
    for(i=1; i<=(n-p); ++i)
        cout<<i<<' ';
    if((p-1)*p/2>k)
    {
        cout<<n-((p-1)*p/2-k)<<' ';
        long long  x=n-((p-1)*p/2-k);
        for(i=n; i>x; --i)
            cout<<i<<' ';
        for(i=x-1; i>(n-p); --i)
            cout<<i<<' ';
    }
    else
    for(i=n; i>(n-p); --i)
    cout<<i<<' ';
}
