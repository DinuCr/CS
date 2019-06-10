#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("fbsearch.in");
ofstream fout("fbsearch.out");

#define nmax 100100

struct nod
{
    int poz,mx,val,ok;
    nod *v[27];
    nod ()
    {
        this->poz = 28;
        for(int i=0; i<27; ++i)
            this->v[i]=NULL;
        this->mx=this->val=this->ok=0;
    }
};

struct sir
{
    int n;
    char s[35];
};

sir v[nmax];
nod *cap;
sir s;
int aux,ans,t,n,m,i;

inline int maj(char x)
{
    if(x<='Z')
        return x-'A';
    if(x>='a')
        return x-'a';
    return 26;
}

void add(nod *&cap,int k,int poz)
{
    if(k==v[poz].n)
        cap->ok=poz;
    else
    {
        if(cap->v[maj(v[poz].s[k])]==NULL)
        {
            nod *q = new nod;
            cap->v[maj(v[poz].s[k])]=q;
            add(q,k+1,poz);
        }
        else
        add(cap->v[maj(v[poz].s[k])],k+1,poz);

        cap->poz = min(cap->poz,maj(v[poz].s[k]));
    }
}

void update(nod *&cap,int k,int val)
{
    if(k==s.n)
    {
        cap->val+=val;
        aux = cap->val;
    }
    else
    {
        update(cap->v[maj(s.s[k])],k+1,val);
        if(aux>cap->mx || (aux==cap->mx && maj(s.s[k])<cap->poz))
        {
            cap->mx=aux;
            cap->poz=maj(s.s[k]);
        }
    }
}

void searchintrie(nod *&cap,int k)
{
    if(k<s.n)
    {
        if(cap->v[maj(s.s[k])]==NULL)
            return;
        searchintrie(cap->v[maj(s.s[k])],k+1);
    }
    else
    {
        if(cap->ok!=0 && cap->mx==0)
            ans = cap->ok;
        else
        searchintrie(cap->v[cap->poz],k);
    }
}

void del(nod *&cap)
{
    for(int i=0; i<27; ++i)
        if(cap->v[i]!=NULL)
            del(cap->v[i]);
    delete(cap);
}

int main()
{
    fin>>t;
    while(t--)
    {
        cap = new nod;
        fin>>n>>m;
        for(i=1; i<=n; ++i)
        {
            fin>>v[i].s;
            v[i].n=strlen(v[i].s);
            add(cap,0,i);
        }
        while(m--)
        {
            char p;
            fin>>p;
            switch(p)
            {
            case 'Q':
                fin>>s.s;
                s.n=strlen(s.s);
                ans = -1;
                searchintrie(cap,0);
                if(ans == -1)
                    fout<<"Search Bing for "<<s.s<<'\n';
                else
                fout<<v[ans].s<<'\n';
                break;
            case 'U':
                int val;
                fin>>s.s>>val;
                s.n=strlen(s.s);
                update(cap,0,val);
                break;
            }
        }
        del(cap);

    }
}
