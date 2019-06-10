#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("numere6.in");
ofstream fout("numere6.out");

#define modulo 9973
#define ll long long

ll ans;
int a,b;

inline ll mod(ll x)
{
    if(x>=modulo)
        return x%modulo;
    return x;
}

int exp(int a,int b)
{
    if(b==1)
        return a;
    else
    if(b%2)
        return mod(exp(a,b-1)*a);
    return mod(exp(mod(a*a),b>>1));
}

ll C(int n,int x)
{
    ll a = 1;
    for(int i=n-x+1; i<=n; ++i)
        a*=i,a=mod(a);
    ll b = 1;
    for(int i=2; i<=x; ++i)
        b*=i,b=mod(b);
    return mod(a*exp(b,modulo-2));
}

void bkt(int x,int p)
{
    if(p==1 && x<=a)
        ans=mod(ans+C(a,x-1));
    for(int i=2; i<=9; ++i)
        if(!(p%i))
            bkt(x+1,p/i);
}

int main()
{
    fin>>a>>b;
    bkt(1,b);
    fout<<ans;
}
