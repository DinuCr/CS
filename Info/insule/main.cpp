#include <iostream>
#include <fstream>
using namespace std;
ifstream f("insule.in");
ofstream g("insule.out");
typedef struct punct
{
    int x,y;
};
char v[102][102],cr;
int nr1,nr2,nr3,i,j,k,z,n,m,ok,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
bool w[102][102];
punct c[10005];
void fill1(int i,int j,char k)
{
    if(v[i][j]==k)
    {
        v[i][j]=-k;
        fill1(i+1,j,k);
        fill1(i-1,j,k);
        fill1(i,j+1,k);
        fill1(i,j-1,k);
    }
    else
    if(k=='1' && v[i][j]=='0' && w[i][j]==0)
    {
        z++;
        c[z].x=i;
        c[z].y=j;
        w[i][j]=v[i][j]=1;
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        f>>v[i][j];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(v[i][j]!='0')
        {
            switch(v[i][j])
            {
            case '1':
                nr1++;
                fill1(i,j,'1');
                break;
            case '2':
                nr2++;
                fill1(i,j,'2');
                break;
            case '3':
                nr3++;
                fill1(i,j,'3');
                break;
            }
        }
    cr-='2';
    g<<nr1<<' '<<nr2<<' '<<nr3<<' ';
    ok=1;
    for(i=1;i<=z && ok;i++)
    {
        for(k=0;k<4;k++)
        if(v[c[i].x+dx[k]][c[i].y+dy[k]]==cr)
        {
            ok=0;
            g<<(int)v[c[i].x][c[i].y];
            break;
        }
        else
        if(v[c[i].x+dx[k]][c[i].y+dy[k]]=='0')
        {
            z++;
            v[c[i].x+dx[k]][c[i].y+dy[k]]=v[c[i].x][c[i].y]+1;
            c[z].x=c[i].x+dx[k];
            c[z].y=c[i].y+dy[k];
        }
    }
}
