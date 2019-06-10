#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
FILE *f=fopen("prod3.in","r");
FILE *g=fopen("prod3.out","w");
long i,n,x,mx1,mx2,mx3,mn1,mn2;
int main()
{
    fscanf(f,"%d",&n);
    mx1=-30001;
    mx2=mx1;
    mx3=mx2;
    mn1=30001;
    mn2=mn1;
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d",&x);
        if(x>mx1)
        {
            mx3=mx2;
            mx2=mx1;
            mx1=x;
        }
        else
        if(x>mx2)
        {
            mx3=mx2;
            mx2=x;
        }
        else
        if(x>mx3)
        mx3=x;

        if(x<mn1)
        {
            mn2=mn1;
            mn1=x;
        }
        else
        if(x<mn2)
        mn2=x;
    }
    if((mx1*mx2*mx3>0 && mn2*mn1<mx2*mx3) || (mx1<0 && mx2<0))
    fprintf(g,"%d %d %d",mx1,mx2,mx3);
    else
    fprintf(g,"%d %d %d",mx1,mn1,mn2);
    fclose(g);
    return 0;
}
