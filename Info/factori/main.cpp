#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("factori.in","r");
FILE *g=fopen("factori.out","w");
int n,m,i,j,nr,x,v[60001],k,n2;
int main()
{
    for(j=4;j<=60000;j+=2)
        v[j]=1;
    for(i=3;i<=30000;i+=2)
    {
        if(v[i]==0)
        for(j=i*2;j<=60000;j+=i)
            v[j]=1;
    }
    for(i=2;i<=60000;i++)
    if(v[i]==0)
    {
        k++;
        v[k]=i;
    }
    v[k+1]=60001;
    fscanf(f,"%d",&n);
    while(n!=0)
    {
        i=1;
        while(v[i]<=n)
        {
            n2=n;
            nr=0;
            while(n2>=v[i])
            {
                nr+=n2/v[i];
                n2/=v[i];
            }
            fprintf(g,"%d ",nr);
            i++;
        }
        fprintf(g,"\n");
        fscanf(f,"%d",&n);
    }
    fclose(g);
    return 0;
}
