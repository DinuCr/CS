#include <iostream>
using namespace std;
struct nod
{
    int val;
    nod *leg;
};
nod *rad,*act,*q;
int i,n,s;
bool prim(int x)
{
    if(x<2)
        return 0;
    for(int i=2;i<x;i++)
        if(x%i==0)
        return 0;
    return 1;
}
void suma(nod *rad)
{
    if(rad->leg!=NULL)
    {
        if(prim(rad->val))
            s+=rad->val;
        suma(rad->leg);
    }
    else
    if(prim(rad->val))
        s+=rad->val;

}
int main()
{
    cin>>n;
    //rad e inceputul, act e actualul/nod curent
    rad=new nod;
    rad->leg=NULL;
    cin>>rad->val;
    //citest separat primul ca sa retin radacina
    //q e nodul cu care fac legatura
    act=rad;
    for(i=1;i<n;i++)
    {
        q=new nod;
        cin>>q->val;
        //aloc memorie, o umplu cu val, si dupa avansez
        act->leg=q;
        q->leg=NULL;
        act=act->leg;
    }
    suma(rad);
    cout<<s;
}
