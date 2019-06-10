#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("retea.in");
ofstream g("retea.out");

vector <int> v[110];
int b[110];
int i,n,m,x,y,k,ok,j;

void df(int x)
{
    b[x]=1;
    for(int i=0; i<v[x].size(); ++i)
        if(v[x][i]!=k && b[v[x][i]]==0)
            df(v[x][i]);
}

int main()
{
    f>>n>>m;
    for(i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i=1; i<=n; ++i)
    {
        k=i;
        if(i==1)
            df(i+1);
        else
            df(i-1);
        b[i]=1;
        ok=0;
        for(j=1; j<=n; ++j)
        {
            if(b[j]==0)
                ok=1;
            b[j]=0;
        }
        g<<ok<<' ';
    }
}
