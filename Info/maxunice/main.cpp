#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("maxunice.in");
ofstream fout("maxunice.out");

int n,i,ans,nr;

int main()
{
    fin>>n;
    for(i=1; ans<=n; ++i)
    {
        ans+=i;
        ++nr;
    }
    --nr;
    fout<<nr<<'\n';
    for(i=1; i<nr; ++i)
    {
        fout<<i<<'\n';
        n-=i;
    }
    fout<<n;
}
