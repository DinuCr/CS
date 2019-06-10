#include<iostream>
#include<fstream>
using namespace std;
ifstream f("foto.in");
ofstream g("foto.out");
int v[105][105],i,j,nr,n,m,mx=0;
void fill1(int x,int y)
{
    if(v[x][y]==0)
    {
        nr++;
        v[x][y]=1;
        fill1(x+1,y);
        fill1(x-1,y);
        fill1(x,y+1);
        fill1(x,y-1);
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        f>>v[i][j];
    for(i=0;i<=n+1;i++)
    {
        v[i][0]=1;
        v[i][m+1]=1;
    }
    for(i=0;i<=m+1;i++)
    {
        v[0][i]=1;
        v[n+1][i]=1;
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(v[i][j]==0)
        {
            nr=0;
            fill1(i,j);
            mx=max(nr,mx);
        }
    g<<mx;
    f.close();
    g.close();
    return 0;
}
