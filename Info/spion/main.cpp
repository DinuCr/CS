#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("spion.in");
ofstream fout("spion.out");

#define ll long long

const int modulo = 100003;

char s[100100];
int n,p,i;

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

int main()
{
    fin>>p;

    int cnt=0;
    fin>>s;
    n = strlen(s);
    for(i=0; i<n; ++i)
        if(s[i]=='E')
            ++cnt;
    if(p==1)
    {
        ++cnt;
        fout<<cnt;
    }
    else
    {
        fout<<comb(n,cnt);
    }
}
