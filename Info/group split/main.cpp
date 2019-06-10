#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    ll n,i,ans=0,k;
    cin>>n;
    k=(ll)sqrt(1LL*n);
    for(i=1; i<=k; ++i)
        if(n%i==0)
            ans += 1 + (n-n/i>=n/i);
    cout<<ans - (1LL*sqrt(n)*sqrt(n)==n);
}
