#include <iostream>

using namespace std;
typedef struct nod
{
    int info;
    nod *st,*dr;
};
nod *rad;
void crearearb(nod *&rad)
{
    int n;
    cin>>n;
    if(n)
    {
        rad=new nod;
        rad->info=n;
        crearearb(rad->st);
        crearearb(rad->dr);
    }
    else
    rad=NULL;
}
void rsd(nod *rad)
{
    if(rad!=NULL)
    {
        cout<<rad->info<<' ';
        rsd(rad->st);
        rsd(rad->dr);
    }
}

void srd(nod *rad)
{
    if(rad!=NULL)
    {
        srd(rad->st);
        cout<<rad->info<<' ';
        srd(rad->dr);
    }
}

void sdr(nod *rad)
{
    if(rad!=NULL)
    {
        sdr(rad->st);
        sdr(rad->dr);
        cout<<rad->info<<' ';
    }
}
int main()
{
    crearearb(rad);
    rsd(rad);
    cout<<endl;
    srd(rad);
    cout<<endl;
    sdr(rad);
}
