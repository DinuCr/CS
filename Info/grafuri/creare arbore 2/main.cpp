#include <iostream>
using namespace std;
typedef struct nod
{
    int info;
    nod *st,*dr;
};
nod *rad;
nod *crearearb()
{
    int n;
    nod *rad;
    cin>>n;
    if(n)
    {
        rad=new nod;
        rad->info=n;
        rad->st=crearearb();
        rad->dr=crearearb();
        return rad;
    }
    else
    return NULL;
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
    rad=crearearb();
    rsd(rad);
    cout<<endl;
    srd(rad);
    cout<<endl;
    sdr(rad);
}
