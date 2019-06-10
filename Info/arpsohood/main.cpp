#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arpsohood.in");
ofstream g("arpsohood.out");

int v[510][510],n,k,i,j;

const int mod = 666013;

int main()
{
    f>>n>>k;

    v[0][0]=1;

    for(i=1; i<=505; ++i)
    for(j=1; j<=505; ++j)
        v[i][j]=j*((v[i-1][j-1]+v[i-1][j]))%mod;

    g<<v[n][k]%mod;
}
