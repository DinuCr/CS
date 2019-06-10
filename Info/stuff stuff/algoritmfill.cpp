#include<iostream>
#include<fstream>
using namespace std;
ifstream f("fill.in");
int v[100][100],n,i,j,x,y,m;
void fill(int x,int y,int k)
{
    if(v[x][y]==0)
    {
        v[x][y]=k;
        fill(x-1,y,k);
        fill(x+1,y,k);
        fill(x,y+1,k);
        fill(x,y-1,k);
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f>>v[i][j];
    f>>x>>y;
    fill(x,y,2);
    for(i=1;i<=n;i++)
    {
    for(j=1;j<=m;j++)
    cout<<v[i][j]<<' ';
    cout<<endl;
    }
    f.close();
    return 0;
}
