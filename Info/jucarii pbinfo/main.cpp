#include <iostream>

using namespace std;

#define ll long long

const int mod = 224737;

int main()
{
    ll n,m;
    cin>>m>>n;
    if(m>n)
    {
        cout<<0;
        return 0;
    }
    ll ans = 1;
    for(int i = n-m+1; i<=n; ++i)
        ans = (ans*i)%mod;
    cout<<ans;
}
