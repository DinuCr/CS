#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("reguli.in");
ofstream fout("reguli.out");

#define nmax 500100

long long v[nmax];
long long p[nmax];
long long n,i,k;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    for(i=2; i<=n; ++i)
        v[i-1]=v[i]-v[i-1];
    --n;
    for(i=2; i<=n; ++i)
    {
        k=p[i-1];
        while(k && v[i]!=v[k+1])
            k=p[k];
        if(v[k+1]==v[i])
            p[i]=k+1;
    }
    fout<<n-p[n]<<'\n';
    for(i=1; i<=n-p[n]; ++i)
        fout<<v[i]<<'\n';
}
