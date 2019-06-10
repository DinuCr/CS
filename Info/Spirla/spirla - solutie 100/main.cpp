#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ifstream fin("spirla.in");
ofstream fout("spirla.out");


#define nmax (int) 1e6+15

int a[nmax];
int b[nmax];
int x[nmax];
int f[nmax]; ///factorial
int v[nmax]; ///combinari
int d1[nmax]; ///rucsac
int d2[nmax]; ///rucsac
int cnt[nmax];
int n,m,p,k,i,j;

inline int mod(ll x)
{
    if(x>=m)
        x%=m;
    return x;
}

int exp(int a,int b)
{
    if(!b)
        return 1;
    if(b&1)
        return mod((ll)a*exp(a,b-1));
    return exp(mod((ll)a*a),b>>1);
}

int comb(int n,int k)
{
    ll ans = f[n];
    int curr = cnt[n]-cnt[n-k]-cnt[k];
    if(curr)
        return 0;
    ans *= (ll)exp(f[n-k],m-2);
    ans = mod(ans);
    ans *= (ll)exp(f[k],m-2);
    ans = mod(ans);

    return ans;
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    fin>>n>>p>>k>>m;
    for(i=1; i<=n; ++i)
        fin>>a[i];
    for(i=1; i<=n; ++i)
        fin>>b[i];
    for(i=1; i<=n; ++i)
        fin>>x[i];

    f[0]=1;
    for(i=1; i<=1e6; ++i)
    {
        cnt[i]=cnt[i-1];
        int x = i;
        while(x%m==0)
            ++cnt[i],x/=m;
        f[i]=mod((ll)f[i-1]*x);
    }

    for(i=1; i<=n; ++i)
        v[i]=mod((ll)comb(a[i],b[i])*exp(x[i],p)),fout<<v[i]<<' ';

    for(i=0; i<=m; ++i)
        d1[i]=d2[i]=1e9;

    int ans = 1;

    d1[1]=d2[1]=1;
    for(i=1; i<=n; ++i)
    {
        for(j=0; j<=m; ++j)
            if(d1[j]<=k)
                d2[mod((ll)j*v[i])]=min(d2[mod((ll)j*v[i])],d1[j]+1),ans=max(ans,mod((ll)j*v[i]));
        for(j=0; j<=m; ++j)
            d1[j]=d2[j];
    }
    fout<<ans;
}
