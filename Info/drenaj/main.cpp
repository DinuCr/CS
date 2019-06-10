#include<iostream>
#include<fstream>
using namespace std;
ifstream f("drenaj.in");
ofstream g("drenaj.out");
int v[102][102],i,j,n,m,ok,nr,w[101][101];
void fill1(int x,int y,int k)
{
    if(v[x][y]<k)
        ok=0;
    else
    if(v[x][y]==k && w[x][y]==0)
    {
    w[x][y]=1;
    fill1(x+1,y,k);
    fill1(x-1,y,k);
    fill1(x,y+1,k);
    fill1(x,y-1,k);
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        f>>v[i][j];
    for(i=0;i<=n;i++)
    {
        v[i][0]=10001;
        v[i][m+1]=10001;
    }
    for(i=0;i<=m;i++)
    {
        v[0][i]=10001;
        v[n+1][i]=10001;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(w[i][j]==0)
        {
            ok=1;
            fill1(i,j,v[i][j]);
            nr+=ok;
        }
    g<<nr;
    f.close();
    g.close();
    return 0;
}
