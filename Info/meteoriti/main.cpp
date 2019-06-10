#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream f("meteoriti.in");
ofstream g("meteoriti.out");
int v[2100][2100],i,j,x1,x2,y1,y2,k,n,m,nr,s,mx,p,mx1,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void fill1(int i,int j)
{
    queue <int> w;
    w.push((i-1)*m+j);
    int x,y,k;
    v[i][j]=-1;
    p=1;
    while(!w.empty())
    {
        x=(w.front()-1)/m+1;
        y=(w.front()-1)%m+1;
        for(k=0;k<4;k++)
        {
            if(v[x+dx[k]][y+dy[k]]==mx)
            {
                w.push((x-1+dx[k])*m+y+dy[k]);
                v[x+dx[k]][y+dy[k]]=-1;
                p++;
            }
        }
        w.pop();
    }
}
int main()
{
    f>>n>>m>>k;
    for(i=1;i<=k;i++)
    {
        f>>x1>>y1>>x2>>y2>>nr;
        v[x1][y1]+=nr;
        v[x1][y2+1]-=nr;
        v[x2+1][y1]-=nr;
        v[x2+1][y2+1]+=nr;
    }
    nr=0;
    for(i=1;i<=n;i++)
    for(j=1;j<=m+1;j++)
    {
        v[i][j]=v[i][j]+v[i-1][j]+v[i][j-1]-v[i-1][j-1];
        mx=max(mx,v[i][j]);
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(v[i][j]==mx)
    {
        p=0;
        fill1(i,j);
        mx1=max(mx1,p);
    }
    else
    {
        nr+=(!v[i][j]);
    }
    g<<mx1<<' '<<nr;
}
