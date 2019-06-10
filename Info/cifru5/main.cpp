#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ifstream f("cifru5.in");
ofstream g("cifru5.out");
int i,j,nr,v[10],w[10],x,mn,n;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x;
        v[x]++;
    }
    for(i=9;i>0;i--)
        if(v[i]!=0)
        break;
    g<<i<<'\n';
    for(i=0;i<=9;i++)
    {
        for(j=0;j<=9;j++)
            w[i]+=v[j]*min(abs(i-j),10-abs(i-j));
    }
    j=0;
    while(v[j]==0)
    j++;
    mn=w[j];
    for(i=j;i<=9;i++)
            mn=min(mn,w[i]);
    g<<mn<<'\n';
    for(i=0;i<=9;i++)
        if(w[i]==mn)
        break;
    g<<i<<'\n';
    for(i=0;i<=9;i++)
        if(w[i]==mn)
        nr++;
    g<<nr;
    f.close();
    g.close();
    return 0;
}
