#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("fractii.in");
ofstream fout("fractii.out");

#define nmax 1000100

long long ind[nmax];

long long i,j,n,ans;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        ind[i]=i;
    for(i=2; i<=n; ++i)
    {
        if(ind[i]==i)
            for(j=i; j<=n; j+=i)
                ind[j]=ind[j]/i*(i-1);
        ans+=ind[i];
    }
    ans*=2;
    ++ans;
    fout<<ans;
}
