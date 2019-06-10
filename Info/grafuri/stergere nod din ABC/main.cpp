#include <iostream>
using namespace std;
typedef struct nod
{
    int info;
    nod *st,*dr;
};
nod *rad;
void inserare(nod *&rad,int m)
{
    if(rad==NULL)
    {
        rad=new nod;
        rad->info=m;
        rad->st=rad->dr=NULL;
    }
    else
    if(m<rad->info)
    inserare(rad->st,m);
    else
    inserare(rad->dr,m);
}
void crearearb(nod *&rad)
{
    int i,m,n;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>m;
        inserare(rad,m);
    }
}
void sterge(nod *&rad,int m)
{
    nod *p,*q;
    if(rad->info<m)
    sterge(rad->dr,m);
    else
    if(rad->info>m)
    sterge(rad->st,m);
    else
    {
        if(rad->st==NULL)
        {
            p=rad;
            rad=p->dr;
            delete(p);
        }
        else
        if(rad->dr==NULL)
        {
            p=rad;
            rad=rad->st;
            delete(p);
        }
        else
        {
            q=rad;
            p=rad->st;
            while(p->dr!=NULL)
            {
                q=p;
                p=p->dr;
            }
            rad->info=p->info;
            if(rad->st==p)
            rad->st=p->st;
            else
            q->dr=p->st;
            delete(p);
        }
    }
}
void RSD(nod *&rad)
{
    if(rad!=NULL)
    {
        cout<<rad->info<<' ';
        RSD(rad->st);
        RSD(rad->dr);
    }
}
int x;
int main()
{
    crearearb(rad);
    cin>>x;
    RSD(rad);
    cout<<endl;
    sterge(rad,x);
    RSD(rad);
    cout<<endl;
}
