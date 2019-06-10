#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("permheap.in");
ofstream fout("permheap.out");

const long long modulo = 666013;

inline long long mod(long long x)
{
    if(x>=modulo)
        return x%modulo;
    return x;
}

long long pow(long long a,long long b)
{
    if(b==0)
        return 1;
    if(b&1)
        return mod(a*pow(a,b-1));
    return mod(pow(mod(a*a),b>>1));
}

long long comb(long long n,long long k)
{
    long long a = 1;
    for(long long i=n-k+1; i<=n; ++i)
        a=mod(a*i);
    long long b = 1;
    for(long long i=1; i<=k; ++i)
        b=mod(b*i);
    return mod(a*pow(b,modulo-2));
}

long long perm(long long n)
{
    if(n<=2)
        return 1;
    long long k=1;
    while(k<=n)
        k<<=1;
    k>>=1;
    long long l = (k>>1) - 1 + min(n+1-k,k>>1);
    long long r = (k>>1) - 1 + max(0LL,n+1-k-(k>>1));
    return mod(mod(comb(n-1,l)*perm(l))*perm(r));

}

int main()
{
    long long n;
    fin>>n;
    fout<<perm(n);
}
