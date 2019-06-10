#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
int i,j,k,n,m,ok,n1,n2;
bool d[1010][1010];
char v[1010][1010],s[2010];
typedef struct co
{
    int x,y;
};
co c1[2010],c2[2010];
ifstream f("drum6.in");
ofstream g("drum6.out");
void avans(co c1[],co c2[],int &n1,int &n2)
{
    int i,mn=1000;
    n2=0;
    for(i=1;i<=n1;i++)
    if(c1[i].x!=-1)
    {
        c2[++n2].x=c1[i].x;
        c2[n2].y=c1[i].y+1;
        if(c2[n2].x==c2[n2-1].x && c2[n2].y==c2[n2-1].y)
            n2--;
        mn=min(mn,v[c1[i].x][c1[i].y+1]-0);
        c2[++n2].x=c1[i].x+1;
        c2[n2].y=c1[i].y;
        if(c2[n2].x==c2[n2-1].x && c2[n2].y==c2[n2-1].y)
            n2--;
        mn=min(mn,v[c1[i].x+1][c1[i].y]-0);
    }
    for(i=1;i<=n2;i++)
        if(v[c2[i].x][c2[i].y]!=mn)
        c2[i].x=-1;
        else
        {
            d[c2[i].x][c2[i].y]=1;
            if(c2[i].x==n && c2[i].y==m)
                ok=0;
        }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        f>>v[i][j];
    c1[1].x=1;
    c1[1].y=1;
    n1=1;
    for(i=1;i<=n;i++)
        v[i][m+1]='z'+1;
    for(j=1;j<=m;j++)
        v[n+1][j]='z'+1;
    d[1][1]=1;
    ok=1;
    while(ok)
    {
        avans(c1,c2,n1,n2);
        if(ok)
        avans(c2,c1,n2,n1);
    }
    i=n;
    j=m;
    s[0]=v[n][m];
    k=1;
    while(i>1 || j>1)
        if(d[i-1][j]==1)
        {
            s[k++]=v[i-1][j];
            i--;
        }
        else
        {
            s[k++]=v[i][j-1];
            j--;
        }
    for(i=k-1;i>=0;i--)
        g<<s[i];
}
