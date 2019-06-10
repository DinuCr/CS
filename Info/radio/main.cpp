#include <iostream>
#include <fstream>
using namespace std;
ifstream f("radio.in");
ofstream g("radio.out");
int c[1100000],w[1100000],v[20],p2[24],ok,n,i,x,nr0,k,j,m;
int main()
{
    f>>n;
    p2[0]=1;
    for(i=1;i<=n+1;i++)
        p2[i]=p2[i-1]*2;
    for(i=0;i<n;i++)
    {
        f>>ok;
        c[1]+=ok*p2[i];
    }
    w[c[1]]=1;
    for(i=1;i<=n;i++)
        v[i]=p2[n+1]-1;
    for(i=1;i<=n;i++)
    {
        f>>k;
        for(j=0;j<k;j++)
        {
            f>>x;
            v[i]-=p2[x-1];
        }
    }
    k=1;
    m=1;
    while(w[4]==0)
    {
        for(i=0;i<n;i++)
        if((c[k]>>i)%2==0)
        {
        x=(c[k] & v[i+1]) + p2[i];
        if(w[x]==0)
        {
            w[x]=w[c[k]]+1;
            m++;
            c[m]=x;
        }
        }
        k++;
    }
    g<<w[4]-1;
}
