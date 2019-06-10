#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const long long mod = 1000000007;
long long v[1001000];
long long d[100100];
long long sum[1001000];
long long n,i;
long long curr;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    sum[0]=1;
    d[0]=1;
    for(i=1; i<=n; ++i)
    {
        if(i-v[i]>0)
            curr = sum[i-v[i]-1];
        if(curr==0)
            ++curr;
        d[i]=(1LL*curr)%mod;
        sum[i]=(d[i]+sum[i-1])%mod;
    }
    long long ans = 0;
    for(i=0; i<=n; ++i)
        ans=(ans+1LL*d[i])%mod;
    cout<<ans;
}
