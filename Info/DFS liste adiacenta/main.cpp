#include <iostream>
#include<fstream>
using namespace std;
ifstream f("DFS.in");
int viz[100],v[100][100],xp,n,i,x,y,u,c[100];
void df(int xp)
{
    int l;
    u++;
    c[u]=xp;viz[xp]=1;
    for(l=1;l<=v[xp][0];l++)
    if(!viz[v[xp][l]])
    {
        df(v[xp][l]);
    }
}
void qsort(int ls,int ld,int p)
{
    int m,i,j,z;
    m=(ls+ls)/2;
    i=ls;
    j=ld;
    z=v[p][m];
    do
    {
        while(v[p][i]<z)
            i++;
        while(v[p][j]>z)
            j--;
        if(i<=j)
        {
            swap(v[p][i],v[p][j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(i<ld)
        qsort(i,ld,p);
    if(j>ls)
        qsort(ls,j,p);
}

int main()
{
    f>>n>>xp;
    while(!f.eof())
    {
        f>>x>>y;
        v[x][0]++;
        v[x][v[x][0]]=y;
        v[y][0]++;
        v[y][v[y][0]]=x;
    }
    for(i=1;i<=n;i++)
        qsort(1,v[i][0],i);
    df(xp);
    for(i=1;i<=n;i++)
        cout<<c[i]<<' ';
}
