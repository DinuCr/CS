#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("patrat1.in","r");
FILE *g=fopen("patrat1.out","w");
int l[8]={-1,-1,0,1,1,1,0,-1},c[8]={0,1,1,1,0,-1,-1,-1},v[202][202],s[10000][2],i,j,n,m,nr,mx,k;
bool stea(int i,int j)
{
    int d,ok;
    ok=true;
        for(d=0;d<8;d++)
            if(v[i+l[d]][j+c[d]]>=v[i][j])
            {
                ok=false;
                return ok;
            }
    return ok;
}
int main()
{
    fscanf(f,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            fscanf(f,"%d",&v[i][j]);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(stea(i,j))
        {
            k++;
            s[k][0]=i;
            s[k][1]=j;
        }
    }
    fprintf(g,"%d\n",k);
    nr=0;
    mx=0;
    for(i=1;i<k;i++)
    for(j=i+1;j<=k;j++)
    {
        if(stea(s[j][0],s[i][1]) && stea(s[i][0],s[j][1]) && s[j][0]-s[i][0]==s[j][1]-s[i][1])
        {
            nr++;
            mx=max(mx,s[j][1]-s[i][1]+1);
        }
    }
    fprintf(g,"%d\n%d\n",nr,mx);
    fclose(g);
    return 0;
}
