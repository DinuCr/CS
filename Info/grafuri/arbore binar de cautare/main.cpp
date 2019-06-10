#include <iostream>
using namespace std;
typedef struct nod
{
    int info;
    nod *st,*dr;
};
nod *rad;
void inserare(nod *&rad,int k)
{
    if(rad!=NULL)
    {
        if(k>rad->info)
        inserare(rad->dr,k);
        else
        if(k<rad->info)
        inserare(rad->st,k);
        else
        cout<<"informatia exista";
    }
    else
    {
        rad=new(nod);
        rad->info=k;
        rad->st=NULL;
        rad->dr=NULL;
    }
}
void SRD(nod *rad)
{
    if(rad!=NULL)
    {
        SRD(rad->st);
        cout<<rad->info<<' ';
        SRD(rad->dr);
    }
}
int i,n,x;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        inserare(rad,x);
    }
    SRD(rad);
    SRD(rad);
}
