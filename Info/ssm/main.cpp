#include <iostream>
#include <fstream>
using namespace std;
int n,v[6000100],i,j,i0,i1,s,mx;
ifstream f("ssm.in");
ofstream g("ssm.out");
int main()
{
    f>>n;
    for(i=1; i<=n; i++)
        f>>v[i];
    j=1;
    i=1;
    mx=v[1];
    s=v[1];
    while(j<n)
    {
        if(i<j)
        {
            if(v[i]<0)
                s-=v[i++];
            else if(s<0)
                s-=v[i++];
            else
                s+=v[++j];
            if(s>mx)
            {
                mx=s;
                i0=i;
                i1=j;
            }
        }
        else
            s+=v[++j];
        if(s>mx)
        {
            mx=s;
            i0=i;
            i1=j;
        }
    }
    if(i<j)
    {
        if(v[i]<0)
            s-=v[i++];
        else if(s<0)
            s-=v[i++];
        if(s>mx)
        {
            mx=s;
            i0=i;
            i1=j;
        }
    }
    g<<mx<<' '<<i0<<' '<<i1;
}
