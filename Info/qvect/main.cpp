#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
FILE *f=fopen("qvect.in","r");
FILE *g=fopen("qvect.out","w");
int v[101][5002],i,j,n,m,x,y,t;
int diferenta(int x,int y)
{
    int i,j,k,mn,z;
    v[x][v[x][0]+1]=2000000010;
    v[y][v[y][0]+1]=2000000010;
    i=1;j=1;
    mn=2000000010;
    for(k=1;k<v[x][0]+v[y][0];k++)
    {
        z=abs(v[x][i]-v[y][j]);
        mn=min(z,mn);
        if(v[x][i]<v[y][j])
            i++;
        else
            j++;
    }
    return mn;
}
int cbinar(int nr,int i)
{
    int x,y,m;
    x=1;
    y=v[i][0];
    while(x<=y)
    {
        m=(x+y)/2;
        if(v[i][m]==nr)
            return m-1;
        else
            if(nr>v[i][m])
            x=m+1;
        else
            y=m-1;
    }
    return y;
}
int median(int i,int j)
{
    int s=0,k,p,s1,z;
    for(k=i;k<=j;k++)
        s+=v[k][0];
    s/=2;
    for(k=i;k<=j;k++)
    {
        for(p=1;p<=v[k][0];p++)
        {
            s1=p;
            for(z=i;z<k;z++)
            {
                if(v[k][p]<v[z][1])
                    s1+=0;
                else
                    if(v[k][p]>v[z][v[z][0]])
                    s1+=v[z][0];
                else
                    s1+=cbinar(v[k][p],z);
            }
            for(z=k+1;z<=j;z++)
            {
                if(v[k][p]<v[z][1])
                    s1+=0;
                else
                    if(v[k][p]>v[z][v[z][0]])
                    s1+=v[z][0];
                else
                    s1+=cbinar(v[k][p],z);
            }
            if(s1==s)
                return v[k][p];
            else
                if(s1>s)
                break;
        }
    }
}
int main()
{
    fscanf(f,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d",&v[i][0]);
        for(j=1;j<=v[i][0];j++)
            fscanf(f,"%d",&v[i][j]);
    }
    for(i=1;i<=m;i++)
    {
        fscanf(f,"%d%d%d",&t,&x,&y);
        if(t==1)
            fprintf(g,"%d\n",diferenta(x,y));
        else
            fprintf(g,"%d\n",median(x,y));
    }
    fclose(g);
    return 0;
}
