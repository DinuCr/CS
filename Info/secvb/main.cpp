#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("secvb.in","r");
FILE *g=fopen("secvb.out","w");
int v[100001],n,t,s,i,j,nr;
int main()
{
    fscanf(f,"%d%d",&n,&t);
    for(i=0;i<n;i++)
    {
        fscanf(f,"%d",&v[i]);
        nr=0;
        while(v[i]!=0)
        {
            nr++;
            v[i]=v[i]&(v[i]-1);
        }
        v[i]=nr;
    }
    nr=0;
    i=0;j=0;
    s=v[0];
    while(j<n)
    {
        if(s<t)
        {
            j++;
            s+=v[j];
        }
        else
        if(s>t)
        {
            s-=v[i];
            i++;
        }
        else
        {
            nr++;
            s-=v[i];
            i++;
        }
    }
    fprintf(g,"%d",nr);
    fclose(g);
    return 0;
}
