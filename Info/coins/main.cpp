#include <iostream>
#include <fstream>
using namespace std;
ifstream f("coins.in");
ofstream g("coins.out");
int p[23],i,x,j,nr,s,S,k,n,ok;
bool v[4200000];
int main()
{
    for(i=0;i<=22;i++)
        p[i]=1<<i;
    x=p[22];
    for(i=0;i<x;i++)
    {
        k=-1;ok=0;
        for(j=0;j<22;j++)
        if(i & p[j])
        {
            if(k!=-1)
            {
            ok=1;
            if(!v[i-p[j]+p[k]] && k!=-1)
            {
                v[i]=1;
                break;
            }
            }
        }
        else
        {
            k=j;
        }
        if(!ok)
            v[i]=1;
    }
    f>>n;
    for(i=1;i<=n;i++)
    {
        nr=0;s=0;
        for(j=0;j<22;j++)
        {
            f>>x;
            nr+=x;
            s+=x*p[j];
        }
        if(v[s])
            S+=nr;
    }
    g<<S;
}
