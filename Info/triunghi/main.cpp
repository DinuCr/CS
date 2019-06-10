#include <iostream>
#include <fstream>
using namespace std;
ifstream f("triunghi.in");
ofstream g("triunghi.out");
int d[1001000],v[20][20][20],r[20],i,j,k,s,n,w[20][20],p,m;
int main()
{
    f>>n>>s;
    for(i=1;i<=n;i++)
    v[n][i][i]=1;
    for(i=n-1;i>0;i--)
        for(j=1;j<=i;j++)
            for(k=1;k<=n;k++)
                v[i][j][k]=v[i+1][j][k]+v[i+1][j+1][k];
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
            for(k=1;k<=n;k++)
                r[k]+=v[i][j][k];
    for(i=1;i<=n;i++)
    p+=r[i];
    m=(n+1)/2;
    s-=p;
    d[0]=1;
    for(i=1;i<=n;i++)
        w[n][i]=1;
    for(j=1;j<=m;j++)
    for(i=r[j];i<=s;i++)
    {
        if(d[i-r[j]]!=0)
        d[i]=j;
    }
    i=s;
    while(i>0)
    {
        w[n][d[i]]++;
        i-=r[d[i]];
    }
    for(i=n-1;i>0;i--)
    for(j=1;j<=i;j++)
    w[i][j]=w[i+1][j]+w[i+1][j+1];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            g<<w[i][j]<<' ';
        g<<'\n';
    }
}
