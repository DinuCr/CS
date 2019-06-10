#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("3color.in");
ofstream fout("3color.out");

vector <int> v[1000];
int viz[1010];
int color[1010];
int mx = 100;
int part[100];
int n,m,i,a,b;

void df(int x)
{
    viz[x]=1;
    for(int i=0; i<mx; ++i)
        part[i]=0;
    for(int i=0; i<v[x].size(); ++i)
        if(color[v[x][i]]!=-1)
            part[color[v[x][i]]]=1;
    int z;
    for(int i=0; i<mx; ++i)
        if(part[i]==0)
        {
            z=i;
            break;
        }
    color[x]=z;
    for(int i=0; i<v[x].size(); ++i)
        if(!viz[v[x][i]])
            df(v[x][i]);
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
    for(i=0; i<n; ++i)
        color[i]=0;
    df(0);
    for(i=0; i<n; ++i)
        fout<<color[i]<<' ';
}
