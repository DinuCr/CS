#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int rmq[20][250100];

int v[25];

int n, m, i, j, p2;

ifstream f("stramosi.in");
ofstream g("stramosi.out");

int main()
{
    for(i=0; i<25; ++i)
        v[i]=(1<<i);

    f>>n>>m;
    for(i=1; i<=n; ++i)
    {
        f>>rmq[0][i];
    }

    int k=log2(n);
    for(i=1; i<=k; ++i)
    {
        for(j=1; j<=n; ++j)
            rmq[i][j]=rmq[i-1][rmq[i-1][j]];
    }

    int p,q;
    for(i=1; i<=m; ++i)
    {
        f>>p>>q;
        while(q && p)
        {
            p2=1;
            for(j=0; p2*2<=q; ++j)
                p2*=2;

            p=rmq[j][p];
            q-=p2;
        }
        g<<p<<'\n';
    }

}
