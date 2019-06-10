#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("aprindere.in");
ofstream fout("aprindere.out");

vector <int> v[1010];
int t[1010];
int w[1010];
int n,m,i,j,ans,x,nr,z;

int main()
{
    fin>>n>>m;
    for(i=0; i<n; ++i)
        fin>>w[i];
    for(i=1; i<=m; ++i)
    {
        fin>>x;
        fin>>t[x]>>nr;
        for(j=1; j<=nr; ++j)
        {
            fin>>z;
            v[x].push_back(z);
        }
    }
    for(i=0; i<n; ++i)
        if(!w[i])
            {
                ans+=t[i];
                for(j=0; j<v[i].size(); ++j)
                    w[v[i][j]]=!w[v[i][j]];
            }
    fout<<ans;
}
