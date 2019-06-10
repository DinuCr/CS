#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("matrice4.in","r");
FILE *g=fopen("matrice4.out","w");
int v[2501],a[2501],n,m,i,j,x,ok,mx,k;
int main()
{
    fscanf(f,"%d%d",&n,&m);
    n=n*m;
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d",&v[i]);
        ok=false;
        if(v[i]%2==0)
                x=v[i]+1;
        else
                x=v[i];
        if(v[i]==0 || v[i]==1)
        x=4;
        else
        while(ok==false)
        {
            ok=true;
            for(j=3;j<=x/2;j+=2)
            if(x%j==0){ok=false;break;}
            x+=2;
        }
        a[i]=x-v[i]-1;
        if(a[i]>mx)mx=a[i];
    }
    m=0;
    for(i=1;i<=n;i++)
    if(a[i]==mx){m++;v[m]=v[i]+mx-1;}
    fprintf(g,"%d %d\n",mx,m);
    ok=true;k=1;
    while(ok)
    {
        ok=false;
        for(i=k;i<m;i++)
            if(v[i]>v[i+1])
        {
            swap(v[i],v[i+1]);
            ok=true;
        }
        k++;
    }
    for(i=1;i<=m;i++)
        fprintf(g,"%d ",v[i]);
    fclose(g);
    return 0;
}
