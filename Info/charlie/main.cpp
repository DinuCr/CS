#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
FILE *f=fopen("charlie.in","r");
FILE *g=fopen("charlie.out","w");
long long p,i,mx,nr,ok,suma,n;
char s[100001],st[100001];
int main()
{
    fscanf(f,"%d%s",&p,&s);

    int z = strlen(s);
    if(p==1)
    {
        for(i=1; i<z; i++)
            if(s[i]<s[i-1] && s[i]<s[i+1])
            {
                nr=3;
                i++;
                while((s[i]<s[i-1] && s[i]<s[i+1])||(s[i]>s[i-1] && s[i]>s[i+1]))
                {
                    nr++;
                    i++;
                }
                if(s[i]<s[i-1])
                    nr--;
                mx=max(nr,mx);
                i--;
            }
        fprintf(g,"%lld",mx);
    }
    else
    {
        st[0]=s[0];
        st[1]=s[1];
        n=2;
        for(i=2; i<z; i++)
        {
            st[n]=s[i];
            while(st[n]>st[n-1] && st[n-1]<st[n-2])
            {
                st[n-1]=st[n];
                n--;
                suma+=max(st[n],st[n-1])-'a'+1;
            }
            n++;
        }
        for(i=0; i<n; i++)
            fprintf(g,"%c",st[i]);
        fprintf(g,"\n%lld",suma);
    }
}
