#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("grarb.in");
ofstream fout("grarb.out");

#define nmax 100100

vector <int> v[nmax];
int viz[nmax];
int n,m,i,a,b,ans1,ans2;

void df(int x,int t)
{
    viz[x]=1;
    for(int i=0; i<v[x].size(); ++i)
        if(viz[v[x][i]]==0)
        {
            df(v[x][i],x);
        }
        else
        if(v[x][i]!=t)
            ++ans1;
}

int main()
{
    fin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1; i<=n; ++i)
        if(!viz[i])
        {
            ++ans2;
            df(i,0);
        }
    fout<<m+ans2-n<<'\n'<<ans2-1;
}
