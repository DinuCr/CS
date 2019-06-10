#include <iostream>
#include <fstream>
using namespace std;
ifstream f("royfloyd.in");
ofstream g("royfloyd.out");
int v[110][110],i,j,k,n;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        f>>v[i][j];
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(v[i][k] && v[k][j] && (v[i][j] > v[i][k] + v[k][j] || !v[i][j]) && i != j)
    v[i][j]=v[i][k]+v[k][j];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            g<<v[i][j]<<' ';
        g<<'\n';
    }
}
