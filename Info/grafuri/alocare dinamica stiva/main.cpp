#include <iostream>

using namespace std;
typedef struct nod
{
    int info;
    nod *leg;
};
nod *vf,*vf1;
void creare(nod *&vf)
{
    int i,n;
    nod *p;
    vf=NULL;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        p=new(nod);
        cin>>p->info;
        p->leg=vf;
        vf=p;
    }
}
void adauga(nod *&vf,int k)
{
    nod *p;
    p=new(nod);
    p->info=k;
    p->leg=vf;
    vf=p;
}
void eliminare(nod *&vf)
{
    nod *p;
    p=vf;
    vf=p->leg;
    delete(p);
}
void stergere(nod *&vf)
{
    nod *p;
    while(p!=NULL)
    {
        vf=p->leg;
        delete(p);
        p=vf;
    }
}
void concatenare(nod *vf1,nod *&vf2)
{
    nod *p;
    p=vf1;
    while(p->leg!=NULL)
    p=p->leg;
    p->leg=vf2;
}
void scindare(nod *&vf,nod *&vf1,int x)
{
    nod *p;
    p=vf;
    while(p->leg->info!=x)
    p=p->leg;
    vf1=p->leg;
    p->leg=NULL;
}
void parcurgere(nod *vf)
{
    while(vf!=NULL)
    {
        cout<<vf->info<<' ';
        vf=vf->leg;
    }
    cout<<'\n';
}
int main()
{
    /*creare(vf);
    parcurgere(vf);
    adauga(vf,6);
    parcurgere(vf);
    eliminare(vf);
    parcurgere(vf);
    stergere(vf);
    parcurgere(vf);
    */creare(vf);
    creare(vf1);
    concatenare(vf,vf1);
    parcurgere(vf);/*
    scindare(vf,vf1,3);
    parcurgere(vf);*/
}
