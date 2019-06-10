#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("jap2.in");
ofstream fout("jap2.out");

#define ll long long

ll p[100100];
ll d[100];
ll power[100];
ll n,k,modulo,q,pmax;

inline ll mod(ll x)
{
    if(x>=modulo)
        return x%modulo;
    return x;
}

void gcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x=1;
        y=0;
    }
    else
    {
        ll x0,y0;
        gcd(b,a%b,x0,y0);
        x=y0;
        y=x0-a/b*y0;
    }
}

ll lgput(ll a,ll b)
{
    if(b==0)
        return 1;
    if(b&1)
        return mod(a*lgput(a,b-1));
    return lgput(mod(a*a),b>>1);
}

void po(ll &nrp,ll &ans, ll n)
{
    int k = pmax;
    int nr = 0;

    for(k=1; power[k]<=n && k<=pmax; ++k)
        nrp+=n/power[k];

    k = pmax;

    while(n>=modulo)
    {
        while(n<power[k])
            --k;
        nr=n/power[k];
        ans=mod(ans*lgput(d[k],nr)*p[nr]);
        n-=power[k]*nr;
    }
    ans=mod(ans*p[n]);
}

ll comb(ll n,ll k)
{
    ll x,y,ap1=0,a1=1,ap2=0,a2=1,bp=0,b2=1;

    po(ap1,a1,n);
    po(ap2,a2,n-k);
    po(bp,b2,k);

    if(ap1-ap2>bp)
        return 0;

    gcd(a2,modulo,x,y);
    if(x<0)
        x+=modulo;
    ll a = mod(a1*x);
    gcd(b2,modulo,x,y);
    if(x<0)
        x+=modulo;
    return mod(1LL*a*x);
}

int main()
{
    fin>>modulo>>q;
    p[0]=1;
    for(int i=1; i<=modulo; ++i)
        p[i]=mod(p[i-1]*i);
    d[1]=p[modulo-1];
    power[1]=modulo;
    ll lim = 1e18+10;
    for(ll i=2,curr=modulo*modulo; power[i-1]<lim/modulo && i<64; ++i,curr*=modulo)
    {
        d[i]=mod(lgput(d[i-1],modulo)*d[1]);
        power[i]=power[i-1]*modulo;
        pmax=i;
    }
    while(q--)
    {
        ll a,b;
        fin>>a>>b;
        fout<<comb(a,b)<<'\n';
    }
}
