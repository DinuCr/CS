#include<iostream>
#include<fstream>
using namespace std;
ifstream f("neuroni.in");
ofstream g("neuroni.out");
int v[101][101],i,j,n,m,k;
int main()
{
    f>>n>>m;
    for(i=1;i<n;i+=2)
        for(j=1;j<=i;j++)
        v[i][j]=1;
    for(k=1;k<=m;k++)
    {
        i=1;j=1;
        while(i<n)
        {
            if(v[i][j]==0)
            {
                v[i][j]=1;
                i++;
            }
            else
            {
                v[i][j]=0;
                i++;
                j++;
            }
        }
        v[i][j]++;
    }
    for(i=1;i<=n;i++)
        g<<v[n][i]<<' ';
    f.close();
    g.close();
    return 0;
}
