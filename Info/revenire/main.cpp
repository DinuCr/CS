#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("revenire.in");
ofstream fout("revenire.out");

#define nmax 100010
#define ll long long

ll v[nmax<<1];
ll a[nmax<<1];
ll last[nmax<<1];
int aib[nmax<<1];
int aint[nmax<<2],n;

#define zeros(x) (x ^ (x-1)) & x

void add(int poz,int x)
{
    for( ; poz<(n<<1); poz+=zeros(poz))
        aib[poz]+=x;
}

int compute(int poz)
{
    int rez = 0;
    for( ; poz>0; poz-=zeros(poz))
        rez+=aib[poz];
    return rez;
}

void update(int a,int b,int x)
{
    for(a+=(n<<1),b+=(n<<1); a<b; a>>=1,b>>=1)
    {
        if(a&1)
        {
            aint[a]=max(aint[a],x);
            ++a;
        }
        if(b&1)
        {
            --b;
            aint[b]=max(aint[b],x);
        }
    }
}

int maxim(int a)
{
    int rez = 0;
    for(a+=(n<<1); a>0; a>>=1)
        rez=max(rez,aint[a]);
    return rez;
}

int main()
{
    int i;
    ll x;
    fin>>n>>x;
    for(i=1; i<=n; ++i)
    {
        fin>>a[i];
        v[i]+=a[i] + v[i-1];
        last[i]=v[i]+last[i-1];
    }
    for(i=n+1; i<(n<<1); ++i)
    {
        v[i]=v[i-1]+a[i-n];
        last[i]=v[i]+last[i-1];
    }
    ll nr = 0;
    ll curr = 0;
    int ans,step;
    for(i=1; i<(n<<1); ++i)
    {
        ans = max(0,i-n);
        for(step=1; step<n; step<<=1);
        for( ; step; step>>=1)
            if(ans+step<=i && v[i]-v[ans+step-1]>x)
                ans+=step;
        nr += i-ans;
        if(i>ans)
        {
            curr += v[i]*(i-ans)-last[i-1]+last[max(0,ans-1)];
            add(ans+1,1);
            add(i+1,-1);
            update(ans+1,i+1,i);
        }
        if(i>=n)
        {
            fout<<curr<<' '<<nr<<'\n';
            nr-=compute(i-n+1);
            curr-=last[maxim(i-n+1)]-last[i-n]-compute(i-n+1)*v[i-n];
        }
    }
}
