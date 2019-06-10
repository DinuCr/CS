#include <iostream>
#include <fstream>
using namespace std;
typedef struct num
{
    int pos,val;
};
ifstream f("minim.in");
ofstream g("minim.out");
num v[1100];
int i1,j1,s,nr,i,n,mn;
void minim()
{
    nr=0;s=0;
    for(i=1;i<=n;i++)
    {
        if(s>0)
        {
            s=v[i].val;
            nr=1;
        }
        else
        {
            s+=v[i].val;
            nr++;
        }
        if(s<mn)
        {
            mn=s;
            j1=i;
            i1=i-nr+1;
        }
    }
    g<<mn<<' '<<v[i1].pos<<' '<<v[j1].pos<<'\n';
    nr=j1-i1+1;
    n-=nr;
    for(i=i1;i<=n;i++)
        v[i]=v[i+nr];
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i].val;
        v[i].pos=i;
    }
    while(n)
    {
        mn=1000000000;
        minim();
    }
}
