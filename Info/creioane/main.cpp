#include<iostream>
#include<fstream>
using namespace std;
ifstream f("creioane.in");
ofstream g("creioane.out");
int v[9001],i,j,n,mx,nr,x;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>v[i]>>x;
    for(i=1;i<=n;i++)
    {
        nr=1;
        j=i;
        while(v[j]!=0)
        {
            nr++;
            j=v[j];
        }
        mx=max(mx,nr);
    }
    g<<mx;
    f.close();
    g.close();
    return 0;
}
