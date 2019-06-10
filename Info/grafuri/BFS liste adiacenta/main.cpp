#include<iostream>
#include<fstream>
using namespace std;
ifstream f("BFS.in");
int v[100][100],viz[100],c[100],i,j,n,x,y,p,u,xp;
int main()
{
    f>>n>>xp;
    while(!f.eof())
    {
        f>>x>>y;
        v[x][0]++;
        v[x][v[x][0]]=y;
    }
    viz[xp]=1;
    c[1]=xp;
    p=1;
    u=1;
    while(p<=u)
    {
        for(j=1;j<=v[c[p]][0];j++)
        if(!viz[v[c[p]][j]])
        {
            u++;
            c[u]=v[c[p]][j];
            viz[v[c[p]][j]]=1;
        }
        p++;
    }
    for(i=1;i<=n;i++)
        cout<<c[i]<<' ';
    return 0;
}
