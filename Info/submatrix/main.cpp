#include <iostream>
#include <fstream>
using namespace std;
ifstream f("submatrix.in");
ofstream g("submatrix.out");
int v[1010][1010],n,mx;
int main()
{
    f>>n;

    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    f>>v[i][j];
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    if(v[i][j]==1)
    {
        v[i][j]=min(v[i-1][j-1],min(v[i-1][j],v[i][j-1]))+1;
        mx=max(mx,v[i][j]);
    }
    g<<mx;
}
