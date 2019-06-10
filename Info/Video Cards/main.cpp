#include <iostream>
#include <algorithm>

using namespace std;

long long v[400100];
long long w[400100];
long long n,i,j,x,mx;
long long ans,curr;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        v[x]++;
        mx=max(mx,x);
    }
    for(i=1; i<=mx*2; ++i)
        w[i]=v[i]+w[i-1];
    for(i=1; i<=mx; ++i)
        if(v[i])
        {
            curr=0;
            for(j=i; j<=mx; j+=i)
                curr+=(w[j+i-1]-w[j-1])*(j)*1LL;
            ans=max(ans,curr);
        }
    cout<<ans;
}
