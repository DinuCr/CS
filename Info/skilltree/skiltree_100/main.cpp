#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

#define nmax (int)(1e4+10)

ifstream fin("skilltree.in");
ofstream fout("skilltree.out");

ll v[nmax];
int i,j,n;

inline int mod (ll x)
{
    if(x >= 1000000007)
        return x%1000000007;
    return x;
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    fin>>n;
    v[1]=v[0]=1;
    for(i=2; i<=n; ++i)
    {
        for(j=i-1; j>=0; j--)
            v[i]+=mod(v[j]*v[i-j-1]);
        v[i]=mod(v[i]);
    }
    fout<<v[n]<<'\n';
    ll ans = 0;
    for(i=n-1; i>n-1-i; --i)
        ans+=mod(v[i]*v[n-1-i]);
    fout<<mod(ans);
}
