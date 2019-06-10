#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long
#define lim (1<<17)

ifstream f("perechi.in");
ofstream g("perechi.out");

typedef struct fact
{
    int d,p;
};

ll n,nr,k,m;
fact d[100];
ll v[10000];

ll gcd(ll a, ll b)
{
    if(!b)
        return a;
    return gcd(b, a%b);
}

void factori(int n)
{
    k=0;
    int i;

    int l = sqrt(n)+1;

    if(n - ((n/2)*2) == 0)
    {
        d[k].d=2;
        d[k].p=1;
        n/=2;
        while(n - ((n/2)*2) == 0)
            ++d[k].p,n/=2;
        ++k;
    }

    for(i=3; i<l; i+=2)
    {
        if(n - ((n/i)*i) == 0)
        {
            d[k].d=i;
            d[k].p=1;
            n/=i;
            while(n - ((n/i)*i) == 0)
                ++d[k].p,n/=i;
            ++k;
        }
    }
    if(n>1)
    {
        d[k].d=n;
        d[k].p=1;
        ++k;
    }
}

inline int po(int a,int b)
{
    if(!b)
        return 1;
    else
    {
        int s=1;
        for(int i=0; i<b; ++i)
            s*=a;
        return s;
    }
}

void bkt(int x,int j)
{
    if(j==k)
        v[m++]=x;
    else
    {
        for(int i=0; i<=d[j].p; ++i)
            bkt(x*po(d[j].d,i),j+1);
    }
}

int main()
{
    f>>n;

    factori(n);

    bkt(1,0);

    sort(v,v+m);
    int nr=0;
    for(int i=m-1; i>=0; --i)
        for(int j=i; j>=0 && v[i]*v[j]>=n; --j)
            if(v[i]*v[j]/gcd(v[i],v[j])==n)
                ++nr;
    g<<nr;
}
