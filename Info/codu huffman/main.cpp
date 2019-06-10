#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
FILE *f=fopen("huffman.in","r");
typedef struct nod
{
    int nr;
    char c;
    nod *st,*dr;
};
nod *rad,*p;
typedef struct nrc
{
    int nr;
    char c;
};
nrc v[100];
int n,i,j,nr,k;
char s[100];
void srd(nod *rad,int nr)
{
    if(rad!=NULL)
    {
        srd(rad->st,nr*10+1);
        if(rad->st==NULL && rad->dr==NULL)
            cout<<rad->c<<' '<<rad->nr<<' '<<nr<<'\n';
        srd(rad->dr,nr*10);
    }
}
int main()
{
    fscanf(f,"%s",&s);
    for(i=0;i<strlen(s);i++)
    {
        nr=0;
        while(s[i]<='9' && s[i]>='0')
        {
            nr=nr*10+s[i]-'0';
            i++;
        }
        k++;
        v[k].nr=nr;
        v[k].c=s[i];
    }
    for(i=1;i<k;i++)
    for(j=i+1;j<=k;j++)
    if(v[i].nr>v[j].nr)
        swap(v[i],v[j]);
    rad=new nod;
    rad->nr=v[1].nr;
    rad->c=v[1].c;
    rad->st=NULL;
    rad->dr=NULL;
    for(i=2;i<=k;i++)
    {
        p=new nod;
        p->dr=new nod;
        p->dr->st=NULL;
        p->dr->dr=NULL;
        p->dr->nr=v[i].nr;
        p->dr->c=v[i].c;
        p->st=rad;
        p->nr=p->st->nr+p->dr->nr;
        rad=p;
    }
    srd(rad,0);
}
