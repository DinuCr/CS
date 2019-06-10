#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("cod5.in","r");
FILE *g=fopen("cod5.out","w");
long long v[101],x,n,i;
int main()
{
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {fscanf(f,"%d",&x);v[x]++;}
    for(i=0;i<100;i++)
        if(v[i]%2==1)fprintf(g,"%d",i);
    fclose(g);
    return 0;
}
