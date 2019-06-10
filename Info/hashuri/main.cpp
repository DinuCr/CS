#include <iostream>
#include <fstream>
using namespace std;
ifstream f("hashuri.in");
typedef struct nr
{
    int x;
    nr *leg;
    nr() {leg = 0;}
};
nr *v[666013],*p,*q;
int n,i,ok,z,x;
int main()
{
    f>>n;
    for(i=0;i<666013;i++)
    {
        v[i]=new nr;
        v[i]->leg=NULL;
    }
    for(i=1;i<=n;i++)
    {
        f>>x>>z;
        switch(x)
        {
        case 1:
            p=v[z%666013];
            ok=1;
            while(p->leg!=NULL)
            {
                if(p->x==z)
                {
                    ok=0;
                    break;
                }
                p=p->leg;
            }
            if(v[z%666013]!=NULL)
            {
                q=new nr;
                q->x=z;
                p->leg=q;
                q->leg=NULL;
            }
            break;
        case 2:
            p=v[z%666013];
            ok=1;
            while(p!=NULL && p->leg!=NULL && p->leg->x!=z)
                p=p->leg;
            if(p->x==z)
            {
                q=p->leg;
                p->leg=q->leg;
                delete q;
            }
            break;
        case 3:
            p=v[z%666013];ok=0;
            while(p->x!=z && p!=NULL)
                p=p->leg;
            if(p->x==z)
                ok=1;
            cout<<ok<<'\n';
        }
    }
}
