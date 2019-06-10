#include <iostream>

using namespace std;

int v[100],n,i,p,mx;

int main()
{
    cin>>n;
    p=1;
    while(n>0)
    {
        mx=max(mx,n%10);
        for(i=1; i<=n%10; ++i)
            v[i]+=p;
        p*=10;
        n/=10;
    }
    cout<<mx<<'\n';
    for(i=1; i<=mx; ++i)
        cout<<v[i]<<' ';
}
