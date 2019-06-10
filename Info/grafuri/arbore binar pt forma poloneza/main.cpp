#include <iostream>
#include <cstring>
using namespace std;
typedef struct nod
{
    char info;
    nod *st,*dr;
};
nod *r;
char s[200],c;
int i,n;
void urm()
{
    i++;c=s[i];
}
void termen(nod *&r);
void factor(nod *&r);
void putere(nod *&r);

void expresie(nod *&r)
{
    nod *p;
    termen(r);
    p=r;
    while(c=='+' || c=='-')
    {
        r=new nod;
        r->info=c;
        r->st=p;
        termen(r->dr);
        p=r;
    }
}

void termen(nod *&r)
{
    nod *p;
    factor(r);
    p=r;
    while(c=='*' || c=='/')
    {
        r=new nod;
        r->info=c;
        r->st=p;
        factor(r->dr);
        p=r;
    }
}

void factor(nod *&r)
{
    nod *p;
    putere(r);
    p=r;
    if(i<n)
    urm();
    while(c=='^')
    {
        r=new nod;
        r->info=c;
        r->st=p;
        putere(r->dr);
        p=r;
        if(i<n)
        urm();
    }
}
void putere(nod *&r)
{
    urm();
    if(c=='(')
       expresie(r);
    else
        {
            r=new nod;
            r->info=c;
            r->st=NULL;
            r->dr=NULL;
        }
}
void RSD(nod *r)
{
    if(r!=NULL)
    {
        RSD(r->st);
        RSD(r->dr);
        cout<<r->info;
    }
}
int main()
{
    cin>>s;
    n=strlen(s);
    expresie(r);
    RSD(r);
}
