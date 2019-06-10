#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("model.in","r");
FILE *g=fopen("model.out","w");
int v[505][505],i,j,m,mx,n,a[501],z,nr,p1,p2,k;
int main()
{
    fscanf(f,"%d",&m);
    mx=0;
    for(i=1;i<=m;i++)
    {
        fscanf(f,"%d",&a[i]);
        a[i]/=2;
        mx=max(a[i],mx);
    }
    n=mx;
    for(i=1;i<=m;i++)
    {
        for(j=n-a[i]+1;j<=n;j++)
        {
            v[j][n-a[i]+1]=i;
            v[n-a[i]+1][j]=i;
        }
    }
    p1=1;
    for(z=2;z<=n;z++)
    {
        if(v[n][z]!=0)
            {
                p2=z;
                k=v[p1][n];
                for(i=p2-1;i<=n;i++)
                for(j=p1+1;j<p2;j++)
                v[i][j]=k;
                for(i=p1+1;i<p2;i++)
                for(j=p1+1;j<=n;j++)
                v[i][j]=k;
                p1=p2;
            }
    }
        p2=n;
        k=v[p1][n];
        p1++;
        for(i=p2;i<=n;i++)
        for(j=p1;j<=p2;j++)
        v[i][j]=k;
        for(i=p1;i<=p2;i++)
        for(j=p1;j<=n;j++)
        v[i][j]=k;
    fprintf(g,"%d\n",n*2);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            fprintf(g,"%d ",v[i][j]);
        for(j=n;j>0;j--)
            fprintf(g,"%d ",v[i][j]);
        fprintf(g,"\n");
    }
    for(i=n;i>0;i--)
    {
        for(j=1;j<=n;j++)
            fprintf(g,"%d ",v[i][j]);
        for(j=n;j>0;j--)
            fprintf(g,"%d ",v[i][j]);
        fprintf(g,"\n");
    }
    fclose(g);
    return 0;
}
