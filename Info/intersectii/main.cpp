#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("intersectii.in","r");
FILE *g=fopen("intersectii.out","w");
int v[4001],i,j,n,m,p;
int cmmdc(int a,int b)
{
  if(a==0)return b;
  return cmmdc(b%a,a);
}
int main()
{
    fscanf(f,"%d %d %d",&n,&m,&p);
    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
        {
            d=cmmdc(i,j);
            if(w[i][j]==0 && d==1)

            v[i+j-cmmdc(i,j)]+=4;
    for(i=1;i<=p;i++)
    {
        fscanf(f,"%d",&j);
        fprintf(g,"%d\n",v[j]);
    }
    fclose(g);
    return 0;
}
