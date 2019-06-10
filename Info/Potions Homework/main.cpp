#include <iostream>
#include <algorithm>

using namespace std;

#define nmax 200100
#define ll long long

const ll mod = 10007;

ll n,l[nmax],i,s;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>l[i];
    }

    sort(l+1,l+n+1);

    s=0;

    for(i=1; i<=(n+1)/2; ++i)
        if(i!=n-i+1)
            s=(s+(l[i]*l[n-i+1])*2)%mod;
        else
            s=(s+l[i]*l[n-i+1])%mod;
    cout<<s;
}
