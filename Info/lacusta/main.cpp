#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("lacusta.in","r");
FILE *g=fopen("lacusta.out","w");
short v[256][256],w[256];
int i,j,min1,min2,p1,s,n,m;
int main()
{
    fscanf(f,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        {fscanf(f,"%d",&min1);
        v[i][j]=min1;}
    min1=0;
    s=v[1][1]+v[n][m];
    v[1][1]=10000;
    v[n][m]=10000;
    for(i=n-1;i>0;i--)
    {
        for(j=1;j<=m;j++)
            if(p1!=j)
                w[j]=v[i][j]+v[i+1][j]+min1;
            else
                w[j]=v[i][j]+v[i+1][j]+min2;
        if(w[1]<w[2])
        {
            min1=w[1];
            p1=1;
            min2=w[2];
        }
        else
        {
            min1=w[2];
            p1=2;
            min2=w[1];
        }
        for(j=3;j<=m;j++)
        if(w[j]<min1)
        {
            p1=j;
            min2=min1;
            min1=w[j];
        }
        else
        if(w[j]<min2)
        min2=w[j];
    }
    s+=min1;
    fprintf(g,"%d",s);
    fclose(g);
    return 0;
}
