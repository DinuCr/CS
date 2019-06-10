#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("furnici1.in","r");
FILE *g=fopen("furnici1.out","w");
int i,l,n,x,mx;
char y;
int main()
{
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&l);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d",&x);
        fscanf(f,"%c",&y);
        switch(y)
            {
        case 'D':
                mx=(l-x>mx)?l-x:mx;
                break;
        case 'S':
                mx=(x>mx)?x:mx;
                break;
            }
    }
    fprintf(g,"%d",mx);
    fclose(g);
    return 0;
}
