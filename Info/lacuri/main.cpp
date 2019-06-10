#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("lacuri.in","r");
FILE *g=fopen("lacuri.out","w");
int v[102][102],x1,x2,y1,y2,i,j,nr,nr1,n,ok,z,x[100000][2];
void fill1(int x,int y)
{
    if(v[x][y]==1)
    {
        x1=min(x1,x);
        x2=max(x2,x);
        y1=min(y1,y);
        y2=max(y2,y);
        nr++;
        v[x][y]=-1;
        fill1(x-1,y);
        fill1(x,y-1);
        fill1(x+1,y);
        fill1(x,y+1);
    }
}
void lee(int x,int y,int k)
{
    if(v[x][y]==0 || v[x][y]>k)
    {
        v[x][y]=k;
        lee(x-1,y,k+1);
        lee(x+1,y,k+1);
        lee(x,y+1,k+1);
        lee(x,y-1,k+1);
    }
}
int main()
{
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            fscanf(f,"%d",&v[i][j]);
        }
    ok=true;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        if(v[i][j]==1)
        {
            x1=n;
            x2=1;
            y1=n;
            y2=1;
            nr=0;
            fill1(i,j);
            if((x2-x1+1)*(y2-y1+1)!=nr)
                ok=false;
            nr1+=ok;
        }
    }
    if(ok==false)
        fprintf(g,"%d",nr1);
    else
    {
        for(i=1;i<=n;i++)
        {
            v[0][i]=-1;
            v[n+1][i]=-1;
            v[i][0]=-1;
            v[i][n+1]=-1;
        }
        fprintf(g,"%d\n",nr1);
        lee(1,1,1);
        i=n;j=n;z=0;
        while(i!=1 || j!=1)
        {
            z++;
            x[z][0]=i;x[z][1]=j;
            if(v[i-1][j]==v[i][j]-1)
            {
                i--;
            }
            else
            if(v[i+1][j]==v[i][j]-1)
            {
                i++;
            }
            else
            if(v[i][j-1]==v[i][j]-1)
            {
                j--;
            }
            else
            if(v[i][j+1]==v[i][j]-1)
            {
                j++;
            }
        }
        fprintf(g,"1 1\n");
        for(i=z;i>0;i--)
            fprintf(g,"%d %d\n",x[i][0],x[i][1]);
    }
    fclose(g);
    return 0;
}
