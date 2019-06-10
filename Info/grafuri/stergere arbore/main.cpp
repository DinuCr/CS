#include <iostream>
#include <fstream>
using namespace std;
typedef struct nod
{
    int x;
    nod *st,*dr;
};
nod *rad;
ifstream f("stergere.in");
void citire(nod *&rad)
{
    int n;cin>>n;
    if(n)
    {
        rad=new nod;
        rad->x=n;
        citire(rad->st);
        citire(rad->dr);
    }
    else
    rad=NULL;
}
void stergere(nod *&rad)
{
    if(rad!=NULL)
    {
    stergere(rad->st);
    stergere(rad->dr);
    if(rad->st!=NULL && rad->st->st==NULL && rad->st->dr==NULL)
        {
            cout<<rad->st->x;
            delete(rad->st);
        }
    if(rad->dr!=NULL && rad->dr->st==NULL && rad->dr->dr==NULL)
        {
            cout<<rad->dr->x;
            delete(rad->dr);
        }
    }
    cout<<rad->x;
    delete(rad);
}
void stergere2(nod *&rad)
{
    if(rad->st!=NULL)
    stergere2(rad->st);
    if(rad->dr!=NULL)
    stergere2(rad->dr);
    cout<<rad->x<<' ';
    delete(rad);
}
void RSD(nod *rad)
{
    if(rad!=NULL)
    {
        cout<<rad->x<<' ';
        RSD(rad->st);
        RSD(rad->dr);
    }
}
int main()
{
    citire(rad);
    RSD(rad);
    stergere2(rad);
    cout<<rad->x;
}
