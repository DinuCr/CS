#include <iostream>
#include <stdio.h>
using namespace std;
FILE *f= fopen("zona.in","r");
FILE *g= fopen("zona.out","w");
int v[220][220],i,j,i0,j0,x,y,l,n,z,nr,k1;
int dx[4]={0,2,-2,0},dy[4]={-2,0,0,2};
void stergere(int x,int y)
{
    if(v[x][y]!=0)
    for(int i=0;i<4;i++)
    {
        if(v[x+dx[i]][y+dy[i]]==v[x][y]-1)
        {
            v[x][y]=0;
            v[x+dx[i]/2][y+dy[i]/2]=0;
            stergere(x+dx[i],y+dy[i]);
        }
    }
}
void fill1(int x,int y)
{
    nr++;
    v[x][y]=-1;
    for(int i=0;i<4;i++)
    {
        if(v[x+dx[i]/2][y+dy[i]/2]==0 && v[x+dx[i]][y+dy[i]]==0)
            fill1(x+dx[i],y+dy[i]);
    }
}
int main()
{
    fscanf(f,"%d%d%d%d",&i0,&j0,&n,&l);
    x=i0=i0*2+1;
    y=j0=j0*2+1;
    ++n;
    n*=2;
    for(i=1;i<l;i++)
    {
        fscanf(f,"%d",&z);
        switch(z)
        {
        case 1:
            x--;
            v[x][y]=i;
            x--;
            break;
        case 2:
            y++;
            v[x][y]=i;
            y++;
            break;
        case 3:
            x++;
            v[x][y]=i;
            x++;
            break;
        case 4:
            y--;
            v[x][y]=i;
            y--;
            break;
        }
        v[x][y]=i;
    }
    fscanf(f,"%d",&z);
    switch(z)
        {
        case 1:
            x--;
            v[x][y]=l;
            x-=1;
            break;
        case 2:
            y++;
            v[x][y]=l;
            y+=1;
            break;
        case 3:
            x++;
            v[x][y]=l;
            x+=1;
            break;
        case 4:
            y--;
            v[x][y]=l;
            y-=1;
            break;
        }
    fprintf(g,"%d\n",l-v[x][y]);
    v[x][y]=l;
    int mn=10000;
    for(int k=0;k<4;k++)
    {
        if(v[x+dx[k]/2][y+dy[k]/2]<mn && v[x+dx[k]/2][y+dy[k]/2]!=0)
            mn=min(v[x+dx[k]][y+dy[k]],mn),k1=k;
    }
    int ok=1;
    for(int k=0;k<3;k++)
    for(int q=k+1;q<4;q++)
    if(v[x+dx[k]/2][y+dy[k]/2]==v[x+dx[q]/2][y+dy[q]/2])
    ok=0;
    if(ok)
    {
        v[x+dx[k1]/2][y+dy[k1]/2]=0;
        stergere(x+dx[k1],y+dy[k1]);
    }
    ok=1;
    for(i=0;i<=n && ok;i+=2)
    for(j=1;j<=n && ok;j+=2)
    if(v[i-1][j]!=0 && v[i+1][j]!=0)
    {
        fill1(i,j+1);
        ok=0;
    }
    fprintf(g,"%d",nr);
}
