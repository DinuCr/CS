#include <iostream>
using namespace std;
typedef struct nod
{
    int info;
    nod *st,*dr;
};
nod *rad1,*rad2;
int mx,i,v[100],p,k;
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
int egali(nod *rad1,nod *rad2)
{
    if(rad1==NULL && rad2==NULL)
    return 1;
    if(rad1==NULL || rad2==NULL)
    return 0;
    else
    return (rad1->info==rad2->info && egali(rad1->st,rad2->st) && egali(rad1->dr,rad2->dr));
}
int verif(nod *rad1,nod *rad2)
{
    if(rad1!=NULL && rad2!=NULL)
        if(rad1->info!=rad2->info)
            return 0;
        else
            return (verif(rad1->st,rad2->st) && verif(rad1->dr,rad2->dr));
    return 1;
}
int main()
{
    crearearb(rad1);
    crearearb(rad2);
    cout<<egali(rad1,rad2)<<verif(rad1,rad2);
}
