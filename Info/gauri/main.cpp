#include <iostream>
#include <fstream>
using namespace std;
int i,j,s,mx,n,m,ok;
char c;
bool v[100][100];
ifstream f("gauri.in");
void fill1(int x,int y,int &ok,int &s)
{
    if(x>n || x<1 || y>m || y<1)
        ok=0;
    else if(v[x][y]==0)
    {
        s++;
        v[x][y]=1;
        fill1(x+1,y,ok,s);
        fill1(x,y+1,ok,s);
        fill1(x-1,y,ok,s);
        fill1(x,y-1,ok,s);
    }
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        f>>c;
        v[i][j]=c-'0';
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(v[i][j]==0)
    {
        s=0;
        ok=1;
        fill1(i,j,ok,s);
        if(ok)
            mx=max(mx,s);
    }
    cout<<mx;
}
