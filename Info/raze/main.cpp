#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("raze.in","r");
FILE *g=fopen("raze.out","w");
int v[140][140],w[140][140],i,j,p,n,m,k,nr,mx;
void optim()
{
    int i,j,i2,j2;
    for(i=1;i<=n;i++)
    {
        v[i][m]=-1;
        v[i][1]=-1;
    }
    for(i=2;i<n;i++)
        for(j=2;j<m;j++)
        w[i][j]=0;
    for(i=1;i<=m;i++)
    {
        v[1][i]=-1;
        v[n][i]=-1;
    }
    i=2;
    j=2;
    while(v[i][j]==0)
    {
        w[i][j]++;
        i++;j++;
    }
    i=n-1;
    j=2;
    while(v[i][j]==0)
    {
        w[i][j]++;
        i--;j++;
    }
    i=n-1;
    j=m-1;
    while(v[i][j]==0)
    {
        w[i][j]++;
        i--;j--;
    }
    i=2;
    j=m-1;
    while(v[i][j]==0)
    {
        w[i][j]++;
        i++;
        j--;
    }
    for(i=2;i<n;i++)
    {
        j=2;
        i2=i+1;
        while(v[i2][j]==0)
        {
            w[i2][j]++;
            i2++;j++;
        }
        j=2;
        i2=i-1;
        while(v[i2][j]==0)
        {
            w[i2][j]++;
            i2--;j++;
        }
        i2=i+1;
        j=m-1;
        while(v[i2][j]==0)
        {
            w[i2][j]++;
            i2++;j--;
        }
        i2=i-1;
        j=m-1;
        while(v[i2][j]==0)
        {
            w[i2][j]++;
            i2--;j--;
        }
    }
    for(j=2;j<m;j++)
    {
        i=2;
        j2=j-1;
        while(v[i][j2]==0)
        {
            w[i][j2]++;
            i++;j2--;
        }
        i=2;
        j2=j+1;
        while(v[i][j2]==0)
        {
            w[i][j2]++;
            i++;j2++;
        }
        i=n-1;
        j2=j-1;
        while(v[i][j2]==0)
        {
            w[i][j2]++;
            i--;j2--;
        }
        i=n-1;
        j2=j+1;
        while(v[i][j2]==0)
        {
            w[i][j2]++;
            i--;j2++;
        }
    }
    mx=0;
    nr=0;
    for(i=2;i<n;i++)
    for(j=2;j<m;j++)
    {
        if(w[i][j]>mx)
        {
            mx=w[i][j];
            nr=1;
        }
        else
        if(w[i][j]==mx)
        nr++;
    }
}
int main()
{
    fscanf(f,"%d",&k);
    for(p=1;p<=k;p++)
    {
        fscanf(f,"%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            fscanf(f,"%d",&v[i][j]);
        optim();
        fprintf(g,"%d %d\n",mx,nr);
    }
    fclose(g);
    fclose(f);
    return 0;
}
