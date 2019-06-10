#include <iostream>
#include <fstream>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

ifstream fin("oite.in");
ofstream fout("oite.out");

unordered_map <int,int> h;
int ans,i,j,s,n;
int v[1100];

int main()
{
    fin>>n>>s;
    for(i=0; i<n; ++i)
        fin>>v[i];
    for(i=0; i<n; ++i)
    {
        for(j=i+1; j<n; ++j)
            ans+=h[s-v[i]-v[j]];
        for(j=0; j<i; ++j)
            ++h[v[i]+v[j]];
    }
    fout<<ans;
}
