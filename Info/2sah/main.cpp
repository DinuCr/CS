#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("2sah.in");
ofstream fout("2sah.out");

const int mod = 100003;

int p,n,k;

int exp(int x)
{
    if(x==1)
        return 3;

    if(x&1)
        return (3*exp(x-1))%mod;

    int p = exp(x>>1)%mod;
    return (1LL*p*p)%mod;
}

typedef struct matrice
{
    long long a,b,c,d,e,f,p,q,r;
};

inline matrice m(matrice a)
{
    a.a%=mod;
    a.b%=mod;
    a.c%=mod;
    a.d%=mod;
    a.e%=mod;
    a.f%=mod;
    a.p%=mod;
    a.q%=mod;
    a.r%=mod;
    return a;
}
inline matrice inmultire(matrice a,matrice b)
{
    matrice p;
    p.a=a.a*b.a+a.b*b.d+a.c*b.p;
    p.b=a.a*b.b+a.b*b.e+a.c*b.q;
    p.c=a.a*b.c+a.b*b.f+a.c*b.r;
    p.d=a.d*b.a+a.e*b.d+a.f*b.p;
    p.e=a.d*b.b+a.e*b.e+a.f*b.q;
    p.f=a.d*b.c+a.e*b.f+a.f*b.r;
    p.p=a.p*b.a+a.q*b.d+a.r*b.p;
    p.q=a.p*b.b+a.q*b.e+a.r*b.q;
    p.r=a.p*b.c+a.q*b.f+a.r*b.r;
    return m(p);
}
matrice exp(matrice n,long long p)
{
    if(p==1)
        return n;
    if(p%2==0)
        return m(exp(inmultire(n,n),p/2));
    return m(inmultire(exp(n,p-1),n));
}

int main()
{
    fin>>p>>n>>k;
    if(p==1)
    {
        if(k==1)
        {
            fout<<1;
            return 0;
        }
        fout<<exp(k-1)%mod;
        return 0;
    }

    matrice x;
    x.a=x.c=0;
    x.b=1;
    x.d=x.e=0;
    x.f=1;
    x.p=x.q=x.r=1;
    x = exp(x,n+1-k);
    fout<<(x.a+x.b+2*x.c)%mod;

}
