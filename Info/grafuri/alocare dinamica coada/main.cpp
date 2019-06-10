#include <iostream>
using namespace std;
typedef struct nod
{
    int info;
    nod *leg;
};
nod *prim,*ultim,*prim1,*ultim1;
void creare(nod *&prim,nod *&ultim)
{
    nod*p;
    int i,n;
    cin>>n;
    prim=ultim=NULL;
    for(i=1;i<=n;i++)
    {
        p=new nod;
        cin>>p->info;
        p->leg=NULL;
        if(prim==NULL)
        prim=ultim=p;
        else
        {
            ultim->leg=p;
            ultim=p;
        }
    }
}
void parcurgere(nod *prim)
{
    while(prim!=NULL)
    {
        cout<<prim->info<<' ';
        prim=prim->leg;
    }
}
void add(nod *&ultim)
{
    nod *p;
    p=new nod;
    cin>>p->info;
    p->leg=NULL;
    ultim->leg=p;
    ultim=p;
}
void el(nod *&prim)
{
    nod *p;
    p=prim->leg;
    delete(prim);
    prim=p;
}
void concatenare(nod *&ultim1,nod *&prim2,nod *ultim2)
{
    ultim1->leg=prim2;
    ultim1=ultim2;
}
void stergere(nod *&prim,nod*&ultim)
{
    nod *p;
    while(p!=ultim)
    {
        p=prim;
        prim=p->leg;
        delete p;
    }
}
void sortare(nod *&prim,nod *&ultim)
{
    nod *p,*q;
    p=prim;
    while(p!=ultim)
    {
        q=p->leg;
        while(q!=NULL)
        {
            if(p->info<q->info)
                swap(p->info,q->info);
            q=q->leg;
        }
        p=p->leg;
    }
}
int main()
{
    creare(prim,ultim);
    sortare(prim,ultim);
    parcurgere(prim);
}
