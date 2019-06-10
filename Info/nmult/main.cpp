#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nmult.in");
ofstream fout("nmult.out");

const long long mod = 666013;

inline long long m(long long x)
{
    if(x>=mod)
        return x%mod;
    return x;
}

long long n,k,w;

void gcd(long long a,long long b,long long &x,long long &y)
{
    if(!b)
    {
        x=1;
        y=0;
    }
    else
    {
        long long x0,y0;
        gcd(b,a%b,x0,y0);
        x=y0;
        y=x0 - a/b*y0;
    }
}

long long comb(long long n,long long k)
{
    long long a=1,b=1;
    for(long long i=n-k+1; i<=n; ++i)
        a=m(a*i);
    for(long long i=1; i<=k; ++i)
        b=m(b*i);
    long long x,y;
    gcd(b,mod,x,y);
    if(x<=0)
        x+=mod;
    return m(x*a);
}

long long compute(long long n,long long k,long long w)
{
    if(w==1)
        return comb(n,k);
    return compute(n-k+1,k,w-1);
}

int main()
{
    fin>>n>>k>>w;
    fout<<compute(n,k,w);
}
