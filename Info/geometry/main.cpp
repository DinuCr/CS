#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("geometry.in");
ofstream fout("geometry.out");

struct segm
{
    long long a,b,c,d;
};

segm v[510];
long long ans,i,j,n;

long long semipl(long long a,long long b,long long c,long long d,long long x,long long y)
{
    return ((x-a)*(d-b)-(c-a)*(y-b));
}

bool intersectie(segm x,segm y)
{
    long long a = semipl(x.a,x.b,x.c,x.d,y.a,y.b);
    long long b = semipl(x.a,x.b,x.c,x.d,y.c,y.d);

    long long c = semipl(y.a,y.b,y.c,y.d,x.a,x.b);
    long long d = semipl(y.a,y.b,y.c,y.d,x.c,x.d);
    if((a*b<=0 && c*d<0) || (a*b<0 && c*d<=0) || (a*b==0 && c*d==0 && ((x.a<=max(y.a,y.c) && x.a>=min(y.a,y.c)) || (x.c<=max(y.a,y.c) && x.c>=min(y.a,y.c)))))
        return 1;
    return 0;
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i].a>>v[i].b>>v[i].c>>v[i].d;
    for(i=1; i<n; ++i)
        for(j=i+1; j<=n; ++j)
            if(intersectie(v[i],v[j]))
                ++ans;
    fout<<ans;
}
