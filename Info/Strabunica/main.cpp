#include <iostream>
#include <fstream>
using namespace std;
long long v[200100],ds[200100],dd[200100],n,i,j,mx;
ifstream f("strabunica.in");
ofstream g("strabunica.out");
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>v[i];
    dd[n]=n+1;
    for(i=n-1;i>0;i--)
    {
        j=i+1;
        while(v[i]<=v[j])
            j=dd[j];
        dd[i]=j;
    }
    ds[1]=0;
    for(i=1;i<=n;i++)
    {
        j=i-1;
        while(v[i]<=v[j])
            j=ds[j];
        ds[i]=j;
    }
    for(i=1;i<=n;i++)
        mx=max(mx,v[i]*(i-ds[i]+dd[i]-i-1));
    g<<mx;
}
