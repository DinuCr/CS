#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
ifstream f("rmq.in");
ofstream g("rmq.out");
int d[100100][20],i,j,k,a,b,m,n,p;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>d[i][0];
    p=(int)log2(n);
    for(j=1;j<=p;j++)
    for(i=1;i+(1<<j)-1<=n;i++)
    d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
    for(i=1;i<=m;i++)
    {
        f>>a>>b;
        k=log2(b-a+1);
        g<<min(d[a][k],d[b-(1<<k)+1][k])<<'\n';
    }
}
