#include <iostream>
#include<fstream>
using namespace std;
ifstream f("BF.in");
int v[100][100],i,c[100],n,x,y,xp,j,viz[100];
void BF(int xp)
{
    int p,i,u;
    p=1;u=1;
    c[1]=xp;
    viz[xp]=1;
    cout<<xp<<' ';
    while(p<=u)
    {
        for(i=1;i<=n;i++)
        if(v[c[p]][i] && !viz[i])
        {
            cout<<i<<' ';
            viz[i]++;
            u++;
            c[u]=i;
        }
        p++;
    }
}
void DF(int xp)
{
    int i;
    cout<<xp<<' ';
    viz[xp]=1;
    for(i=1;i<=n;i++)
    if(v[xp][i]==1 && !viz[i])
    DF(i);
}
int main()
{
    f>>n>>xp;
    while(!f.eof())
    {
        f>>x>>y;
        v[x][y]=1;
        v[y][x]=1;
    }


    DF(xp);
}
