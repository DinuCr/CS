#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("triplete.in");
ofstream fout("triplete.out");

#define pb push_back

vector <int> v[4100];
int viz[4100];
int i,n,m,j,k,a,b,ans;

int main()
{
    fin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        fin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(i=1; i<=n; ++i)
    {
        for(j=0; j<v[i].size(); ++j)
            viz[v[i][j]]=1;
        for(j=0; j<v[i].size(); ++j)
        if(v[i][j]>i)
        {
            int x = v[i][j];
            for(k=0; k<v[x].size(); ++k)
                if(v[x][k]>x && viz[v[x][k]])
                    ++ans;
        }
        for(j=0; j<v[i].size(); ++j)
            viz[v[i][j]]=0;
    }
    fout<<ans;
}
