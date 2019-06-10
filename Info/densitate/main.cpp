#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("densitate.in");
ofstream fout("densitate.out");

#define nmax 500100

int v[nmax];
int a,b,q,n,k,i,j;

int main()
{
    fin>>n>>q;
    k = sqrt(n);
    v[1]=1;
    for(i=2; i<=k; ++i)
    {
        for(j=i*i; j<=n; j+=i)
            v[j]=1;
    }
    int s=0;
    for(i=1; i<=n; ++i)
    {
        s+=v[i];
        v[i]=i-s;
    }
    while(q--)
    {
        fin>>a>>b;
        fout<<v[b]-v[a-1]<<'\n';
    }
}
