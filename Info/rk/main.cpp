#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("rk.in");
ofstream fout("rk.out");

struct nod
{
    int nr;
    nod *st,*dr;
    nod ()
    {
        this->st=NULL;
        this->dr=NULL;
        nr=0;
    }
};

nod *r;

void add(int x)
{
    int c;
    int nr=0;
    nod *p = r;
    nod *q;
    while(nr<33)
    {
        ++nr;
        c = x%2;
        x/=2;
        if(c)
        {
            if(p->dr!=NULL)
            {
                p->nr++;
                p=p->dr;
            }
            else
            {
                q=new nod;
                p->dr=q;
                p->nr++;
                p=p->dr;
            }
        }
        else
            {
            if(p->st!=NULL)
            {
                p->nr++;
                p=p->st;
            }
            else
            {
                q=new nod;
                p->st=q;
                p->nr++;
                p=p->st;
            }
        }
    }
    p->nr++;
}

int query(int rest,int k)
{
    int nr = 0,c;
    nod *p = r;
    while(nr<k)
    {
        c=rest%2;
        rest/=2;
        if(c)
        {
            if(p->dr!=NULL)
                p=p->dr;
            else
                return 0;
        }
        else
        {
            if(p->st!=NULL)
                p=p->st;
            else
                return 0;
        }
        ++nr;
    }
    return p->nr;
}

int n;

int main()
{
    int i,x,q,rest,k;
    fin>>n;
    r=new nod;
    for(i=1; i<=n; ++i)
    {
        fin>>x;
        add(x);
    }
    fin>>q;
    for(i=1; i<=q; ++i)
    {
        fin>>rest>>k;
        fout<<query(rest,k)<<'\n';
    }
}
