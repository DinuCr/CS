#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
FILE *f=fopen("spioni1.in","r");
FILE *g=fopen("spioni1.out","w");
int n,i;
char s[4100],c1,c2;
void fct(int ls, int ld)
{
    if(ld-ls>1)
    {
    char v[100],w[100];
    int i=-1,j=-1,k;
    for(k=ls;k<=ld;k+=2)
    {
        i++;
        v[i]=s[k];
    }
    for(k=ls+1;k<=ld;k+=2)
    {
        j++;
        w[j]=s[k];
    }
    for(k=0;k<=i;k++)
        s[k+ls]=v[k];
    for(k=0;k<=j;k++)
        s[k+ls+i+1]=w[k];
    cout<<s<<'\n';
    fct(ls,(ld/2));
    fct((ld/2+1),ld);
    }
}
int main()
{
    fscanf(f,"%c%c%s",&c1,&c2,&s);
    n=strlen(s);
    fct(0,n-1);
    //fprintf(g,"%s",s);
    cout<<s;
}
