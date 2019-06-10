#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
ifstream f("compresie.in");
ofstream g("compresie.out");
char s[1000010],v[1010][1010];
int n,nr,sm,i,m,j,x;
void co(int i1,int j1,int i2,int j2)
{
    if(i1<=i2 && j1<=j2)
    {
        i++;
        if(s[i]=='*')
        {
            co(i1,j1,(i1+i2)/2,(j1+j2)/2);
            co(i1,(j1+j2)/2+1,(i1+i2)/2,j2);
            co((i1+i2)/2+1,j1,i2,(j1+j2)/2);
            co((i1+i2)/2+1,(j1+j2)/2+1,i2,j2);
        }
        else
        {
            while(s[i]<'a' || s[i]>'z')
                i++;
            int k,j;
            for(k=i1;k<=i2;k++)
            for(j=j1;j<=j2;j++)
                v[k][j]=s[i];
        }
    }
}
int main()
{
    f.get(s,1000010);
    x=strlen(s);sm=0;
    for(i=0;i<x;i++)
    {
        if(s[i]<='9' && s[i]>='0')
        {
            nr=s[i]-'0';i++;
            while(s[i]<='9' && s[i]>='0')
            {
                nr=nr*10+s[i]-'0';
                i++;
            }
            sm+=nr;
        }
        else
        if(s[i]<='z' && s[i]>='a')
        sm++;
        else
        if(s[i]=='*')
        m++;
    }
    n=sqrt(sm);
    g<<m<<'\n';
    i=-1;
    co(1,1,n,n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            g<<v[i][j];
        g<<'\n';
    }
}
