#include <iostream>
#include <fstream>
using namespace std;
ifstream f("joc3.in");
ofstream g("joc3.out");
int v[5010][2],p,mx,m,n,k,i,nr;
int main()
{
    f>>n>>k>>m;
    for(i=1;i<=k;i++)
        f>>v[i][0]>>v[i][1];
    while(n<m)
    {
        mx=n;
        for(i=1;i<=k;i++)
        if(n>=v[i][0] && v[i][1]>mx)
        {
            mx=v[i][1];
            p=i;
        }
        if(mx==n)
            break;
        n=v[p][1];
        v[p][1]=0;
        nr++;
    }
    g<<nr;
}
