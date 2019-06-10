#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("monstri.in");
ofstream fout("monstri.out");

#define ll long long
const int modulo = 1e9+7;

inline int mod(ll x)
{
    if(x>=modulo)
        return x%modulo;
    return x;
}

int exp(ll a,int b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b&1)
        return mod(a*exp(a,b-1));
    return mod(exp(mod(a*a),b>>1));
}

int main()
{
    int n,x;
    fin>>n;
    ll ans = 0;
    for(int i=1; i<=n; ++i)
    {
        fin>>x;
        ans=mod(ans+exp(2,x));
    }
    fout<<ans;
}
