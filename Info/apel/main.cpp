#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#define fs fscanf
using namespace std;
FILE *f=fopen("apel.in","r");
ofstream g("apel.out");
typedef struct vv
{
    char nume;
    int val;
};
vv valv[300];
typedef struct fu
{
    char nume;
    char exp[300];
};
fu funct[300];
char s[300];
int nrv,nrf,n,i,j,k,ok;
int calcul();
int calcul(char s[],int n,int v[],int &ls);

int factor(char s[],int n,int v[],int &ls)
{
    int nr=1;
    while(ls<n && s[ls]!=')' && s[ls]!='-' && s[ls]!='+')
    {
        if(s[ls]<='9' && s[ls]>='0')
            nr*=s[ls]-'0';
        else if(s[ls]<='z' && s[ls]>='a')
            nr*=v[s[ls]-'a'];
        else if(s[ls]=='(')
        {
            ls++;
            nr*=calcul(s,n,v,ls);
        }
        ls++;
    }
    return nr;
}
int calcul(char s[],int n,int v[],int &ls)
{
    int nr=0,ok=1;
    while(ls<n && s[ls]!=')')
    {
        if(s[ls]=='-')
            ok=-1;
        else if(s[ls]=='+')
            ok=1;
        else
            nr+=ok*factor(s,n,v,ls),ls--;
        ls++;
    }
    return nr;
}
int functie (char c,int v[10])
{
    int i,k;
    for(i=0; i<nrf; ++i)
        if(funct[i].nume==c)
        {
            k=i;
            break;
        }
    int n=strlen(funct[k].exp);
    int ls=0;
    return calcul(funct[k].exp,n,v,ls);
}
int apelfunctie(char c,int &ls)
{
    int v[10];
    int i=0;
    while(s[ls]!=')')
    {
        if(s[ls]<='9' && s[ls]>='0')
            v[i++]=s[ls]-'0';
        else if(s[ls]<='z' && s[ls]>='a')
        {
            for(int j=0; j<nrv; ++j)
                if(valv[j].nume==s[ls])
                {
                    v[i++]=valv[j].val;
                    break;
                }
        }
        else if(s[ls]<='Z' && s[ls]>='A')
            {
                ls+=2;
                v[i++]=apelfunctie(s[ls-2],ls);
            }
        ls++;
    }
    return functie(c,v);
}
int main()
{
    fs(f,"%s",&s);

    n=strlen(s);
    for(i=0; i<n; ++i)
    {
        if(s[i]<='z' && s[i]>='a')
        {
            ok=1;
            for(j=0; j<nrv; j++)
                if(valv[j].nume==s[i])
                {
                    ok=0;
                    break;
                }
            if(ok)
                valv[nrv++].nume=s[i];
        }
        else if(s[i]<='Z' && s[i]>='A')
        {
            ok=1;
            for(j=0; j<nrf; j++)
                if(funct[j].nume==s[i])
                {
                    ok=0;
                    break;
                }
            if(ok)
                funct[nrf++].nume=s[i];
        }
    }
    for(i=0; i<nrv; ++i)
    {
        char c[10];
        fs(f,"%s",&c);
        for(j=0; j<nrv; ++j)
            if(valv[j].nume==c[0])
                break;
        int nc=strlen(c);
        for(k=2; k<nc; k++)
            valv[j].val=valv[j].val*10+c[k]-'0';
    }
    char c;
    for(k=0; k<nrf; ++k)
    {
        fs(f,"%c",&c);
        fs(f,"%c",&c);
        funct[k].nume=c;
        while(c!='=')
            fs(f,"%c",&c);
        fs(f,"%s",&funct[k].exp);
    }
    int ls=2;
    g<<apelfunctie(s[0],ls);
}
