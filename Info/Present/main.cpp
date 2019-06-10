#include <iostream>

using namespace std;

long long v[100100],w[100100],n,z,m;

bool verif(long long x)
{
    for(int i=1; i<=n; ++i)
        w[i]=0;
    int curr=0;
    long long s=0;
    for(int i=1; i<=n; ++i)
    {
        if(v[i]+curr<x)
        {
            long long p = x - v[i] - curr;
            s+=p;
            w[min(i+m,n+1)]-=x-v[i]-curr;
            curr+=p;
        }
        curr+=w[i+1];
    }
    if(s<=z)
        return 1;
    return 0;
}

long long bs(long long s,long long d)
{
    if(s+1>=d)
        return s;
    else
    if(verif((s+d)/2))
        bs((s+d)/2,d);
    else
        bs(s,(s+d)/2);
}

int main()
{
    cin>>n>>z>>m;
    for(long long i=1; i<=n; ++i)
        cin>>v[i];
    cout<<bs(1,10000000000);
}
