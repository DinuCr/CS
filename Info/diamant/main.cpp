#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

ifstream fin("diamant.in");
ofstream fout("diamant.out");

#define limita 60000
#define modulo 10000

int v[1010];
int dp[120000];
int a[120000],b[120000];
int l,c,n,mx,i,j,s;

int main()
{
    fin>>l>>c>>s;
    for(i=1; i<=l; ++i)
        for(j=1; j<=c; ++j)
        {
            v[++n]=i*j;
            mx+=i*j;
        }
    dp[limita]=1;
    for(i=1; i<=n; ++i)
    {
        for(j=mx+limita; j>=limita-mx; --j)
            if(dp[j])
            {
                b[j-v[i]]+=dp[j];
                a[j+v[i]]+=dp[j];
            }
        for(j=limita-mx; j<=mx+limita; ++j)
        {
            dp[j]+=a[j]+b[j];
            a[j]=b[j]=0;
        }
        if(i%10==0)
            for(j=limita-mx; j<=mx+limita; ++j)
            {
                dp[j]%=modulo;
            }
    }
    if(abs(s)>mx)
        fout<<0;
    else
        fout<<dp[s+limita]%modulo;
}
