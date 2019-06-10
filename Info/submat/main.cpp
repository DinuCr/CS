#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("submat.in");
ofstream fout("submat.out");

int v[1010];
int i,x,n,m,mx,j;

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            fin>>x;
            if(!x)
                v[i]++;
        }
    sort(v+1,v+n+1);
    for(i=n; i>0; --i)
        mx=max(mx,v[i]*(n-i+1));
    fout<<mx;
}
