#include<iostream>
#include<fstream>
using namespace std;
ifstream f("leecoada.in");
typedef struct punct
{
    int x,y,c;
};
punct c[100];
int n,m,i,j,i1,i2,x0,y0,x1,y1,v[100][100],dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void citire()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        f>>v[i][j];
    f>>x0>>y0>>x1>>y1;
}
void lee()
{
    int ok;
    c[1].x=x0;
    c[1].y=y0;
    i1=1;
    i2=1;
    ok=1;
    for(i=1;i<=n;i++)
    {
        v[i][0]=1;
        v[i][m+1]=1;
    }
    for(i=1;i<=m;i++)
    {
        v[0][i]=1;
        v[n+1][i]=1;
    }
        for(i=i1;i<=i2 && ok;i++)
        {
            for(j=0;j<4;j++)
            if(v[c[i].x+dx[j]][c[i].y+dy[j]]==0)
            {
                i2++;
                c[i2].x=c[i].x+dx[j];
                c[i2].y=c[i].y+dy[j];
                c[i2].c=c[i].c+1;
                if(c[i2].x==x1 && c[i2].y==y1)
                {
                    cout<<c[i2].c;
                    ok=0;
                    break;
                }
            }

        }
}
int main()
{
    citire();
    lee();
    f.close();
    return 0;
}
