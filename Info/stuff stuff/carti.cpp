#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("carti1.in","r");
FILE *g=fopen("carti1.out","w");
int n,x,i,nr,v[100001];
int main()
{
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d",&x);
        v[x]=i;
    }
    for(i=1;i<n;i++)
        if(v[i]>v[i+1])nr++;
    fprintf(g,"%d",nr);
    fclose(g);
    return 0;
}
