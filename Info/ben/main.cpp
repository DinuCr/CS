#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("ben.in");
ofstream fout("ben.out");

#define mod 32173
#define nmax 30100
#define tmax 30000

int v[nmax],i,n,k,ans,sum;

inline void modulo(int &x)
{
    if(x>=mod)
        x%=mod;
}

int aranj(int n,int k)
{
    int ans = 1;
    for(int i = n-k+1; i<=n; ++i)
    {
        ans*=i;
        modulo(ans);
    }
    return ans;
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        int a,b;
        fin>>a>>b;
        ++v[a];
        --v[b];
    }
    int sum = 0;
    for(i=1; i<=tmax; ++i)
    {
        sum+=v[i];
        v[i]=sum;
        k=max(k,sum);
    }
    fout<<k<<' ';
    ans=1;
    for(i=1; i<tmax; ++i)
    {
        ans *=aranj(k-v[i-1],v[i]-v[i-1]);
        modulo(ans);
    }
    fout<<ans;
}
