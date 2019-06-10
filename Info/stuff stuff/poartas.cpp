#include<iostream>
#include<fstream>
using namespace std;
ifstream f("poartas.in");
ofstream g("poartas.out");
int v[251][251],n,w[5001][2],d[5001],x,y,nr,i;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y>>w[i][0]>>w[i][1];
        v[x][y]=i;
    }
    for(i=1;i<=n;i++)
        d[i]=v[w[i][0]][w[i][1]];
    for(i=1;i<=n;i++)
        *clase echivalenta*
    f.close();
    g.close();
    return 0;
}
