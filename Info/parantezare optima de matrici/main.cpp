#include <iostream>
#include <fstream>
using namespace std;
ifstream f("podm.in");
ofstream g("podm.out");
long long v[505],d[505][505],n,i,j,k;
int main()
{
    f>>n;
    for(i=0;i<=n;i++)
        f>>v[i];
    for(i=1;i<=n;i++)
        d[i][i]=0;
    for(i=1;i<n;i++)
        d[i][i+1]=v[i-1]*v[i]*v[i+1];
    for(i=2;i<n;i++)
    for(j=1;j<=n-i;j++)
    {
        d[j][i+j]=100000000000000000;
        for(k=j;k<i+j;k++)
            d[j][i+j]=min(d[j][i+j],d[j][k]+d[k+1][i+j]+v[j-1]*v[k]*v[i+j]);
    }
    g<<d[1][n];
    return 0;
}
