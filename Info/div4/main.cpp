#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("div4.in");
ofstream fout("div4.out");

#define ll long long

const ll modulo = 1000003;

char s[100100];
ll dpar[100100];
ll dimpar[100100];
ll p[100100];
ll n,k;

inline ll mod(ll x)
{
    if(x>=modulo)
        return x%modulo;
    return x;
}

ll gcd(ll a,ll b,ll &x,ll &y)
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

ll comb(ll n,ll k)
{
    ll a,b,x,y;

    a=p[n];
    gcd(p[n-k],modulo,x,y);
    if(x<0)
        x+=modulo;
    a=mod(a*x);
    b=p[k];

    gcd(b,modulo,x,y);
    if(x<0)
        x+=modulo;
    return mod(1LL*a*x);
}

int main()
{
    ll i;
    fin>>s>>k;
    n = strlen(s);
    if(k==n-1)
    {
        ll ans=0;
        for(i=0; i<n; ++i)
            if(s[i]=='4' || s[i]=='8')
                ++ans;
        fout<<ans;
        return 0;
    }
    p[0]=1;
    for(i=1; i<=n; ++i)
        p[i]=mod(1LL*p[i-1]*i);

    ll ans = 0;
    ll lim = 1;
    for(i=n-1; lim<=k+2; --i,++lim)
    {
        if(s[i]=='2' || s[i]=='6')
            dimpar[i]=1;
        else
        if(s[i]=='4' || s[i]=='8')
            dpar[i]=1;
        dpar[i]+=dpar[i+1];
        dimpar[i]+=dimpar[i+1];
    }
    for(i=n-2,lim=2; lim<=k+2; --i,++lim)
    {
        if((s[i]-'0')%2==0)
        {
            ans+=1LL*comb(n-lim,k-lim+2)*dpar[i+1];
        }
        else
        {
            ans+=1LL*comb(n-lim,k-lim+2)*dimpar[i+1];
        }
        ans=mod(ans);
    }
    fout<<ans;
}
