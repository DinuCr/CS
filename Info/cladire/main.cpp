#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cladire.in");
ofstream g("cladire.out");
int v[1002][1002],i,j,m,n,k,mx,p;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
           for(j=1;j<=m;j++)
           v[i][j]=1;
    f>>k;
    for(i=1;i<=k;i++)
    {
        f>>j>>p;
        v[j][p]=0;
    }
    mx=1;
    for(i=2;i<=n;i++)
    for(j=2;j<=m;j++)
    {
        if(v[i][j]!=0)
            v[i][j]=min(min(v[i-1][j],v[i-1][j-1]),min(v[i-1][j],v[i][j-1]))+1;
        if(v[i][j]>mx)mx=v[i][j];
    }
    g<<mx;
    f.close();
    g.close();
    return 0;
}
