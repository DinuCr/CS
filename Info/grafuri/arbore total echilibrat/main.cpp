#include <iostream>
#include <cmath>
using namespace std;
typedef struct nod
{
    int info;
    nod *st,*dr;
};
nod *rad;
int mx,i,v[100],p,k,ok;
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
int h(nod *rad)
{
    if(rad==NULL)
    return -1;
    else
    return 1+max(h(rad->st),h(rad->dr));
}
void ech(nod *rad)
{
    if(rad!=NULL)
    if(h(rad->st)-h(rad->dr)>1 || h(rad->st)-h(rad->dr)<-1)
    ok=false;
    else
    {
        ech(rad->st);
        ech(rad->dr);
    }
}
int main()
{
    crearearb(rad);
    ok=true;
    ech(rad);
    cout<<ok;
}
