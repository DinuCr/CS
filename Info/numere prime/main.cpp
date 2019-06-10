#include <cstdio>
#include <bitset>
#include <iostream>
using namespace std;

FILE *f=fopen("prim.in","r");
FILE *g=fopen("prim.out","w");

#define nmax 1400000

bitset <nmax/2+2> v;
long long i,j,n,mn,nr,x;


int main()
{
    nr=1;
    fscanf(f,"%lld",&n);
    for(i=1; (((i*i)<<1) + (i<<1))<=nmax && nr<n; ++i)
    {
        if(!v[i])
        {
            for(j=(((i*i)<<1) + (i<<1)); (j<<1) +1<=nmax; j+=(i<<1) +1 )
                v[j]=1;
        }
    }
    for(i=1 ; (i<<1) +1<=nmax && nr<n; ++i)
    {
        if(!v[i])
            nr++;
    }
    for( ; (i<<1) +1<=nmax; ++i )
        if(!v[i])
        {
            x=((i*i)<<2) + (i<<2) + 1;
            fprintf(g,"%lld",x);
            break;
        }
}
