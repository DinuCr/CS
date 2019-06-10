#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
FILE *f=fopen("comp.in","r");
FILE *g=fopen("comp.out","w");
int n,i,nr,ok,w[1001];
char v[260];
void verificare(char v[])
{
    int n,nr1,nr0,s1,s2,j,i;
    n=strlen(v);
    i=0;
    nr1=0;
    nr0=0;
    s1=0;
    while(v[i]!='<' && v[i]!='>')
    {
        if(v[i]<='9' && v[i]>='0')
            nr0=nr0*10+v[i]-'0';
        else
        if(v[i]=='+')
            {
                s1+=nr1;
                nr1=0;
            }
        else
        if(v[i]=='m')
            {
                nr1+=nr0*1000;
                nr0=0;
            }
        else
        if(v[i]=='s')
            {
                nr1+=nr0*100;
                nr0=0;
            }
        else
        if(v[i]=='z')
            {
                nr1+=nr0*10;
                nr0=0;
            }
        else
        if(v[i]=='u')
            {
                nr1+=nr0;
                nr0=0;
            }
        i++;
    }
    s1+=nr1;
    nr1=0;
    nr0=0;
    s2=0;
    j=i;
    while(i<n)
    {
        if(v[i]<='9' && v[i]>='0')
            nr0=nr0*10+v[i]-'0';
        else
        if(v[i]=='+')
            {
                s2+=nr1;
                nr1=0;
            }
        else
        if(v[i]=='m')
            {
                nr1+=nr0*1000;
                nr0=0;
            }
        else
        if(v[i]=='s')
            {
                nr1+=nr0*100;
                nr0=0;
            }
        else
        if(v[i]=='z')
            {
                nr1+=nr0*10;
                nr0=0;
            }
        else
        if(v[i]=='u')
            {
                nr1+=nr0;
                nr0=0;
            }
        i++;
    }
    s2+=nr1;
    if(v[j]=='<')
    {
        nr++;
        if(s1<s2)
            ok=1;
        else
        ok=0;
    }
    else
    if(s1>s2)
        ok=1;
    else
    ok=0;
}
int main()
{
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%s",&v);
        verificare(v);
        w[i]=ok;
    }
    fprintf(g,"%d\n",nr);
    for(i=1;i<=n;i++)
        fprintf(g,"%d\n",w[i]);
    fclose(g);
    return 0;
}
