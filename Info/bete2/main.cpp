#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("bete2.in");
ofstream fout("bete2.out");

int v[3010];
int n,i,j,ans;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
    }
    sort(v+1,v+n+1);
    for(i=1; i<=n; ++i)
        if(v[i]!=v[i-1])
            for(j=i+1; j<=n; ++j)
                if(j==i+1 || v[j]!=v[j-1])
                    if(v[i]+v[j]<=1e9 && binary_search(v+1,v+n+1,v[i]+v[j]))
                        ++ans;
    fout<<ans;
}
