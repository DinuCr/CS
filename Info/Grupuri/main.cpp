#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define nmax (int) 1e5+10

ifstream fin("grupuri.in");
ofstream fout("grupuri.out");

int v[nmax];
int n,k;

bool check(ll x)
{
    ll curr = 0;
    for(int i=1; i<=n; ++i)
        curr+=min((ll)v[i],x);
    if(curr>=x*k)
        return 1;
    return 0;
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    ll s = 0;
    fin>>k>>n;
    for(int i=1; i<=n; ++i)
        fin>>v[i],s+=v[i];
    ll i = 1;
    ll ans = 0;
    for( ; i<s/k; i<<=1);
    for( ; i; i>>=1)
    {
        if(ans + i<=s/k && check(ans+i))
            ans+=i;
    }
    fout<<ans;
}
