#include<iostream>
#include<fstream>
using namespace std;
ifstream f("gradina1.in");
ofstream g("gradina1.out");
int v[1001][1001],w[1001][1001],i,j,n,p,k,x,y,nr,mx;
int main()
{
    f>>n>>p>>k;
    for(i=1;i<=p;i++)
    {
        f>>x>>y;
        v[x][y]++;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        w[i][j]=w[i-1][j]+w[i][j-1]-w[i-1][j-1]+v[i][j];
    for(i=k;i<=n;i++)
        for(j=k;j<=n;j++)
        {
            x=w[i][j]+w[i-k][j-k]-w[i-k][j]-w[i][j-k];
            if(x>mx)
            {
                mx=x;
                nr=1;
            }
            else
            if(x==mx)
            nr++;
        }
    g<<mx<<endl<<nr;
    f.close();
    g.close();
    return 0;
}
