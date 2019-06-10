#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("munte.in");
ofstream fout("munte.out");

long long dp[105][55][55][2];
int p[55];
int i,n,d,k,z,s,j;

int main()
{
    fin>>n>>d>>k;
    for(i=1; i<=k; ++i)
    {
        fin>>p[i];
    }
    dp[0][0][0][0]=1;
    //dist,inaltime,pct,varf
    for(i=0; i<d; ++i)
        for(j=(i==0 || i==d)?0:1; j<=n; ++j)
            for(z=0; z<=k; ++z)
                for(s=0; s<2; ++s)
                    if(dp[i][j][z][s])
                    {
                        if(j+1<d)
                            dp[i+1][j+1][(z<k)?(j+1==p[z+1])+z:z][(j+1==n)|s]+=dp[i][j][z][s];
                        dp[i+1][j][(z<k)?(j==p[z+1])+z:z][s]+=dp[i][j][z][s];
                        if(j-1>=0)
                            dp[i+1][j-1][(z<k)?(j-1==p[z+1])+z:z][s]+=dp[i][j][z][s];
                    }
    fout<<dp[d][0][k][1];
}
