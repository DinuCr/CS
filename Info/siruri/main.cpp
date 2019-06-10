#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("siruri.in");
ofstream fout("siruri.out");

int v[15];
int k,n,m;

void bkt(int k)
{
    if(k==m+1)
    {
        for(int i=1; i<=m; ++i)
            fout<<v[i]<<' ';
        fout<<'\n';
    }
    else
    for(int i=v[k-1]+1; ((i<v[k-1]+3 && k>1) || (k==1 && i<=n)) && i<=(n-m+k); ++i)
    {
        v[k]=i;
        bkt(k+1);
    }
}

int main()
{
    fin>>n>>m;
    bkt(1);
}
