#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("functii.in");
ofstream fout("functii.out");

#define ll long long

const int modulo = 30103;

int n,s;

ll mod(ll x)
{
    if(x>=modulo)
        return x%modulo;
    return x;
}

void gcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1;
        y=0;
    }
    else
    {
        int x0,y0;
        gcd(b,a%b,x0,y0);
        x=y0;
        y=x0-a/b*y0;
    }
}


ll comb(int n,int k)
{
    int i;
    ll a=1,b=1;
    for(i=n-k+1; i<=n; ++i)
        a=mod(a*i);
    for(i=1; i<=k; ++i)
        b=mod(b*i);
    int x,y;
    gcd(b,modulo,x,y);
    if(x<=0)
        x+=modulo;
    return mod(a*x);
}

ll lgpow(ll a,ll b)
{
    if(!b)
        return 1;
    if(b&1)
        return mod(a*lgpow(a,b-1));
    return mod(lgpow(mod(a*a),b>>1));
}

int main()
{
    fin>>n>>s;
    fout<<mod(comb(n,s)*(lgpow(2,s)-2));
}
