#include <iostream>
#include <stdio.h>
using namespace std;
int n,m,i,j,k;
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
int a[1025],b[1025],v[1025][1025],w[1025];
int main()
{
    fscanf(f,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&a[i]);
    for(j=1;j<=m;j++)
        fscanf(f,"%d",&b[j]);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(a[i]!=b[j])
            v[i][j]=max(v[i-1][j],v[i][j-1]);
        else
            v[i][j]=v[i-1][j-1]+1;
    }
    fprintf(g,"%d\n",v[n][m]);
    i=n;
    j=m;
    while(i>0)
    {
        if(a[i]==b[j])
        {
            k++;
            w[k]=b[j];
            i--;
            j--;
        }
        else
        if(v[i-1][j]<v[i][j-1])
        j--;
        else
        i--;
    }
    for(i=k;i>0;i--)
        fprintf(g,"%d ",w[i]);
}
