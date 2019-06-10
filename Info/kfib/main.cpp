#include <iostream>
#include <fstream>
using namespace std;
ifstream f("kfib.in");
ofstream g("kfib.out");
typedef struct matrice
{
    long long a,b,c,d;
};
matrice p;
long long n;
inline matrice m(matrice a)
{
    a.a%=666013;
    a.b%=666013;
    a.c%=666013;
    a.d%=666013;
    return a;
}
inline matrice inmultire(matrice a,matrice b)
{
    matrice p;
    p.a=a.a*b.a+a.b*b.c;
    p.c=a.c*b.a+a.d*b.c;
    p.b=a.a*b.b+a.b*b.d;
    p.d=a.c*b.c+a.d*b.d;
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
    p.a=0;
    p.b=1;
    p.c=1;
    p.d=1;
    p=exp(p,n);
    g<<p.c;
}
