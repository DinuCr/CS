#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("roata.in","r");
FILE *g=fopen("roata.out","w");
int i,n,p,v[102002],w[365][3],j,x,ok;
long long s;
int minim()
{
    int p;
    p=1;
    while(w[p][0]==0 && p<=n)
        p++;
    for(i=p;i<=n;i++)
    {
        if(w[p][0]>w[i][0])
        p=i;
    }
    return p;
}
int main()
{
    fscanf(f,"%d%d",&n,&p);
    for(i=1;i<=p;i++)
        {
            fscanf(f,"%d",&v[i]);
            s+=v[i];
        }
    fprintf(g,"%lld\n",s);
    j=n;
    for(i=1;i<=n;i++)
    {
        w[i][0]=v[i];
        w[i][1]=i;
        w[i][2]=i;
    }
    while(j<=p)
    {
        x=w[minim()][0];
        for(i=1;i<=n;i++)
            w[i][0]-=x;
        for(i=1;i<=n;i++)
        if(w[i][0]==0)
        {
            fprintf(g,"%d ",w[i][1]);
            j++;
            w[i][0]=v[j];
            w[i][1]=j;
        }
    }
    ok=true;
    while(ok)
    {
        ok=false;
        for(i=1;i<n;i++)
        if(w[i][0]<w[i+1][0])
        {
            swap(w[i][0],w[i+1][0]);
            swap(w[i][1],w[i+1][1]);
            swap(w[i][2],w[i+1][2]);
            ok=true;
        }
        else
        if(w[i][0]==w[i+1][0])
        if(w[i][2]<w[i+1][2])
        {
            swap(w[i][0],w[i+1][0]);
            swap(w[i][1],w[i+1][1]);
            swap(w[i][2],w[i+1][2]);
            ok=true;
        }

    }
    i=1;
    while(w[i][0]!=0)
    {
        i++;
    }
    i--;
    for(j=i;j>0;j--)
        fprintf(g,"%d ",w[j][1]);
    fprintf(g,"\n%d",w[1][2]);
    fclose(g);
    return 0;
}
