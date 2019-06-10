#include <iostream>

using namespace std;

long long v[1000100];
long long n,x,i;

int main()
{
    cin>>n>>x;
    long long ans=0;
    for(i=1; i<=n; ++i)
    {
        long long a;
        cin>>a;
        ans+=v[x ^ a];
        v[a]++;
    }
    cout<<ans;
}
