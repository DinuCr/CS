#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("metrou5.in");
ofstream fout("metrou5.out");

long long v[100010];
long long fa[1000010];
const long long mod = 1000000007;
long long ans;

#define mp make_pair
#define f first
#define s second

long long modulo(long long x)
{
    if(x>=mod)
        return x%mod;
    return x;
}

void gcd(long long a,long long b,long long &x1,long long &y1)
{
    if(!b)
    {
        x1=1;
        y1=0;
    }
    else
    {
        long long x0,y0;
        gcd(b,a%b,x0,y0);
        x1 = y0;
        y1 = x0 - a/b*y0;
    }
}

long long compute(long long p,long long n)
{
    long long ans = 0;
    long long a = fa[n+p-1];
    long long b = fa[n-1];
    long long x,y;
    gcd(b,mod,x,y);
    if(x<0)
        x+=mod;
    ans = modulo(a*x);
    gcd(fa[p],mod,x,y);
    if(x<0)
        x+=mod;
    ans = modulo(ans*x);
    return ans;
}

int main()
{
    long long n,k,i;
    fa[0]=1;
    for(i=1; i<=1000000; ++i)
        fa[i]=modulo(fa[i-1]*i);
    fin>>n>>k;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    vector <pair<long long,long long> > w;
    w.push_back(mp(1,0));
    for(i=1; i<=n; ++i)
        if(v[i]!=-1)
            w.push_back(mp(v[i],i));
    w.push_back(mp(k,n+1));
    ans = 1;
    for(i=1; i<w.size(); ++i)
    {
        if(w[i].f<w[i-1].f)
        {
            ans = 0;
            break;
        }
        if(w[i].s-w[i-1].s>1)
            ans*=compute(w[i].s-w[i-1].s-1,w[i].f-w[i-1].f+1);
        ans = modulo(ans);
    }
    fout<<ans;
}
