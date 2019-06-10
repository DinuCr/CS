#include <iostream>
#include <fstream>
using namespace std;
ifstream f("obst.in");
typedef struct coord
{
    int x,y;
};
coord c[10000];
int i,j,nr,n,m,d,k,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},v[100][100],w[100][100];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        f>>v[i][j];
        w[i][j]=2000;
    }
    nr=1;
    c[1].x=1;
    c[1].y=1;
    w[1][1]=0;
    for(i=1;i<=nr;i++)
    {
        for(k=0;k<4;k++)
        if(v[c[i].x+dx[k]][c[i].y+dy[k]]!=0)
        {
            if(v[c[i].x][c[i].y]==1)
            {
                if(v[c[i].x+dx[k]][c[i].y+dy[k]]==1)
                {
                if(k<2)
                    d=1;
                else
                    d=3;
                }
                else
                if(v[c[i].x+dx[k]][c[i].y+dy[k]]==2)
                    d=2;
            }
            else
            if(v[c[i].x][c[i].y]==2)
            {
                if(v[c[i].x+dx[k]][c[i].y+dy[k]]==2)
                {
                if(k>1)
                    d=1;
                else
                    d=3;
                }
                else
                if(v[c[i].x+dx[k]][c[i].y+dy[k]]==1)
                    d=2;
            }
            if(w[c[i].x][c[i].y]+d<w[c[i].x+dx[k]][c[i].y+dy[k]])
            {
                w[c[i].x+dx[k]][c[i].y+dy[k]]=w[c[i].x][c[i].y]+d;
                nr++;
                c[nr].x=c[i].x+dx[k];
                c[nr].y=c[i].y+dy[k];
            }
        }
    }
    if(w[n][m]!=2000)
    cout<<w[n][m];
    else
    cout<<-1;
}
