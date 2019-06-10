#include <iostream>

using namespace std;
typedef struct nod
{
    int info;
    nod *st,*dr;
};
nod *rad;
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
void rsd(nod *rad,int k)
{
    if(rad!=NULL)
    {
        v[k]++;
        mx=max(mx,k);
        rsd(rad->st,k+1);
        rsd(rad->dr,k+1);
    }
}
int h(nod *rad)
{
    if(rad==NULL)
    return -1;
    else
    return 1+max(h(rad->st),h(rad->dr));
}
int main()
{
    crearearb(rad);
    rsd(rad,0);mx=0;
    for(i=0;i<=mx;i++)
    if(v[i]>mx)
    {
        mx=v[i];
        p=i;
    }
    cout<<v[p];
}
