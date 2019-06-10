#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f("trie.in");
ofstream g("trie.out");

int p,m;
char s[25];

struct nod
{
    int info,n;
    nod *t;
    nod *v[26];
    nod ()
    {
        for(int i=0; i<26; ++i)
            v[i]=NULL;
        info=n=0;
        t=NULL;
    }
};

nod *rad;

void add(nod *&p,int k)
{
    if(k<m)
    {
        p->n++;
        if(p->v[s[k]-'a']==NULL)
        {
            p->v[s[k]-'a']=new nod;
            p->v[s[k]-'a']->t=p;
        }
        add(p->v[s[k]-'a'],k+1);
    }
    else
    if(k==m)
    {
        p->n++;
        p->info++;
    }
}

void del(nod *&p,int k)
{
    if(k<m)
    {
        del(p->v[s[k]-'a'],k+1);
        p->n--;
        if(p->n==0)
        {
            p->t->v[s[k-1]-'a']=NULL;
            delete(p);
        }
    }
    if(k==m)
    {
        p->info--;
        p->n--;
        if(p->n==0)
        {
            p->t->v[s[k-1]-'a']=NULL;
            delete(p);
        }
    }
}

void query(nod *&p,int k)
{
    if(k<m)
    {
        if(p->v[s[k]-'a']==NULL)
            g<<"0\n";
        else
            query(p->v[s[k]-'a'],k+1);
    }
    if(k==m)
    {
        g<<p->info<<'\n';
    }
}

void pref(nod *&p,int k)
{
    if(k<m)
    {
        if(p->v[s[k]-'a']==NULL)
            g<<k<<'\n';
        else
        pref(p->v[s[k]-'a'],k+1);
    }
    if(k==m)
    {
        g<<k<<'\n';
    }
}

int main()
{
    char c;
    f>>p;
    f>>s;

    rad=new nod;
    rad->n++;

    while(!f.eof())
    {
        switch(p)
        {
        case 0:
            m=strlen(s);
            add(rad,0);
            break;
        case 1:
            m=strlen(s);
            del(rad,0);
            break;
        case 2:
            m=strlen(s);
            query(rad,0);
            break;
        case 3:
            m=strlen(s);
            pref(rad,0);
            break;
        }


        f>>p;
        f>>s;
    }
}
