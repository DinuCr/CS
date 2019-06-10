#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("dezastru.in");
ofstream fout("dezastru.out");

long double d[30][30],p[30];
int n,i,j,k,s;

int main()
{
    fin>>n>>k;
    for(i=1; i<=n; ++i)
        fin>>p[i];
    for(i=0; i<=n; ++i)
        d[i][0]=1;
    for(i=1; i<=n; ++i)
        for(j=1; j<=i; ++j)
            d[i][j]=d[i-1][j]+d[i-1][j-1]*p[i];
    long double s=d[n][k];
    for(i=k+1; i<=n; ++i)
        s/=i;
    for(i=2; i<=n-k; ++i)
        s*=i;
    fout<<s;
}
