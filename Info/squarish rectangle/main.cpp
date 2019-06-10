#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    ll a,b,n,k;
    cin>>a>>b;
    n=a*b;
    k = sqrt(n);
    while(n%k!=0)
        --k;
    cout<<n/k-k;
}
