#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("game.in");
ofstream fout("game.out");

#define nmax 205

int v[nmax];
int d[nmax][nmax];
int n,i,j,ans=-1e9;

int main()
{
    fin>>n;
    int sum = 0;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
        sum+=v[i];
    }
    for(i=1; i<=n; ++i)
        for(j=n; j>=i; --j)
        {
            if(i>1)
                d[i][j]=v[j] + max(d[i-1][j+1],d[i][j+2]);
            else
                d[i][j]=v[j] + d[i][j+2];

            if(i==j)
                ans=max(ans,d[i][j]);
        }
    fout<<ans<<' '<<sum-ans;
}
