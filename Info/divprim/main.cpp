#include <iostream>
#include <fstream>

using namespace std;

ifstream f("divprim.in");
ofstream g("divprim.out");

#define nmax 1001000
#define kmax 8

int v[nmax+10];
int ans[nmax+10][kmax+2];
int n,k,i,j,t,a,b;

int main()
{
    for(i=2; i<nmax; ++i)
        if(!v[i])
        {
            for(j=2*i; j<nmax; j+=i)
                ++v[j];
            v[i]=1;
        }
    for(i=1; i<nmax; ++i)
        {
            for(j=0; j<kmax; ++j)
                ans[i][j]=ans[i-1][j];
            if(v[i]<kmax)
                ans[i][v[i]]=i;
        }
    f>>t;
    for( ; t--; )
    {
        f>>a>>b;
        g<<ans[a][b]<<'\n';
    }
}
