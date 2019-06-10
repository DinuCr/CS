#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("furnici1.in","r");
FILE *g=fopen("furnici1.out","w");
int i,l,n,x,mx;
char y;
int main()
{
    fscanf(f,"%d",&l);
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d",&x);
        fscanf(f,"%c",&y);
        fscanf(f,"%c",&y);
        switch(y)
            {
        case 'D':
                mx=max(l-x,mx);
                break;
        case 'S':
                mx=max(mx,x);
                break;
            }
    }
    fprintf(g,"%d",mx);
    fclose(g);
    return 0;
}
