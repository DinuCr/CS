#include<iostream>
#include<fstream>
using namespace std;
ifstream f("alee.in");
ofstream g("alee.out");
typedef struct punct
{
    int x,y,c;
};
punct c[5001];
int v[200][200],x0,x1,yy,yyy,n,m,i,j,dx[4]={0,1,-1,0},dy[4]={1,0,0,-1};
int lee(int x0,int yy)
{
    int j,i,i1,i2,ok;
    c[1].x=x0;
    c[1].y=yy;
    c[1].c=1;
    i1=1;
    i2=1;
    v[x0][yy]=1;
    ok=true;
    for(i=i1;i<=i2 && ok;i++)
    {
        for(j=0;j<4;j++)
        if(v[c[i%5000].x+dx[j]][c[i%5000].y+dy[j]]==0)
        {
            i2++;
            c[i2%5000].x=c[i%5000].x+dx[j];
            c[i2%5000].y=c[i%5000].y+dy[j];
            c[i2%5000].c=c[i%5000].c+1;
            v[c[i2%5000].x][c[i2%5000].y]=c[i2%5000].c;
            if(c[i2%5000].x==x1 && c[i2%5000].y==yyy)
            {
                g<<c[i2%5000].c;
                ok=false;
                break;
            }
        }
    }
}
int main()
{
    int x,y;
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        v[x][y]=-1;
    }
    for(i=1;i<=n;i++)
    {
        v[i][0]=-1;
        v[i][n+1]=-1;
        v[0][i]=-1;
        v[n+1][i]=-1;
    }
    f>>x0>>yy>>x1>>yyy;
    lee(x0,yy);
    f.close();
    g.close();
    return 0;
}
