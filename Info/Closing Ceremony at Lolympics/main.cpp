#include <iostream>

using namespace std;

const int mod = 1e9+7;

int dp[100100];
int v[1100];
int n,i,j,k;

int main()
{
    cin>>n>>k;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    dp[0]=1;
    for(i=1; i<=n; ++i)
    {
        for(j=k-1; j>=0; --j)
            if(dp[j] && j+v[i]<k)
                dp[j+v[i]]=(dp[j]+dp[j+v[i]])%mod;
    }
    long long ans = 1;
    for(i=1; i<=n; ++i)
        ans = ans*2%mod;
    for(i=0; i<k; ++i)
        ans = (1LL*ans+1LL*2*mod-1LL*2*dp[i])%mod;
    cout<<ans;
}
