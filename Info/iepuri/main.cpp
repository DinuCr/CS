#include <iostream>
#include <fstream>
using namespace std;
ifstream f("iepuri.in");
ofstream g("iepuri.out");
typedef struct matrice
{
    long long a,b,c,d,e,f,p,q,r;
};
matrice p;
long long n,i,s,a,b,c,x,y,z;
inline matrice m(matrice a)
{
    a.a%=666013;
    a.b%=666013;
    a.c%=666013;
    a.d%=666013;
    a.e%=666013;
    a.f%=666013;
    a.p%=666013;
    a.q%=666013;
    a.r%=666013;
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
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y>>z>>a>>b>>c>>s;
        p.a=0;
        p.b=0;
        p.c=c;
        p.d=1;
        p.e=0;
        p.f=b;
        p.p=0;
        p.q=1;
        p.r=a;
        p=exp(p,s-2);
        g<<(x*p.c+y*p.f+z*p.r)%666013<<'\n';
    }
}
