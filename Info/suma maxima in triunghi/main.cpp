#include <iostream>
#include <fstream>
using namespace std;
ifstream f("triunghi.in");
int v[100][100],d[100][100],i,j,n,mx;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    for(j=1;j<=i;j++)
    f>>v[i][j];
    d[1][1]=v[1][1];
    for(i=2;i<=n;i++)
    for(j=1;j<=i;j++)
    {
        d[i][j]=max(d[i-1][j],d[i-1][j-1])+v[i][j];
        mx=max(mx,d[i][j]);
    }
    cout<<mx;

}
