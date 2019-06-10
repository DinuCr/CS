#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define nmax 1000100

int v[nmax],i,n,k,ans;

int main()
{
    fin>>n>>k;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    sort(v+1,v+n+1);
    --k;
    ans = 1e9;
    for(i=k+1; i<=n; ++i)
        ans=min(ans,v[i]-v[i-k]);
    fout<<ans;
}
