#include<iostream>
#include<fstream>
using namespace std;
ifstream f("startrek.in");
ofstream g("startrek.out");
int w[10001],d,v,i,nr,n,t,vit[10001],dist[10001];
int main()
{
    f>>n>>t;
    if(t==0)
        nr=n;
    else
    {
    for(i=1;i<=n;i++)
        f>>dist[i];
    for(i=1;i<=n;i++)
        f>>vit[i];
    for(i=1;i<=n;i++)
        w[(dist[i]/vit[i])/t]++;
    for(i=0;i<=10000;i++)
        if(w[i]!=0 && i>=nr)
        {
            nr+=min(w[i],i-nr+1);
        }

    }
    g<<nr;
    f.close();
    g.close();
    return 0;
}
