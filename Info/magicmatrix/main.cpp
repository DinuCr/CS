#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("magicmatrix.in");
ofstream fout("magicmatrix.out");

int t,v[510][510];

int main()
{
    fin>>t;
    while(t--)
    {
        int n;
        fin>>n;
        int i,j;
        for(i=1; i<=n; ++i)
            for(j=1; j<=n; ++j)
                fin>>v[i][j];
        int ok = 1;
        for(i=2; i<=n && ok; ++i)
            for(j=1; j<n && ok; ++j)
                if(v[i][j]+v[i-1][j+1]!=v[i][j+1]+v[i-1][j])
                    ok=0;
        if(ok)
            fout<<"YES\n";
        else
            fout<<"NO\n";
    }
}
