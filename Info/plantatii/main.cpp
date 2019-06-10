#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("plantatii.in");
ofstream fout("plantatii.out");

int v[1010][1010];
int ds[1010][1010];
int dp[1010][1010];
int par[1000];
int impar[1000];
int t,i,j,n,w,ans;

bool check(int x)
{
    int curr;
    int lim1 = n-x+1;
    for(int i=1; i<=lim1; ++i)
        for(int j=1; j<=lim1; ++j)
        {
            curr = dp[i+x-1][j+x-1] - dp[i-1][j-1];
            curr += ds[i+x-1][j] - ds[i-1][j+x];
            if(x&1)
                curr-=v[(i+i+x-1)>>1][(j+j+x-1)>>1];
            if(curr<=w)
                return 1;
        }
    return 0;
}

void bspar(int ls,int ld)
{
    if(ls>ld)
        return;
    int m = (ls+ld)>>1;
    if(par[m]<=n && check(par[m]))
    {
        ans = max(ans,par[m]);
        bspar(m+1,ld);
    }
    else
    bspar(ls,m-1);
}

void bsimpar(int ls,int ld)
{
    if(ls>ld)
        return;
    int m = (ls+ld)>>1;
    if(impar[m]<=n && check(impar[m]))
    {
        ans = max(ans,impar[m]);
        bsimpar(m+1,ld);
    }
    else
    bsimpar(ls,m-1);
}


int main()
{
    fin>>t;
    int curr = 1;
    for(i=1; i<=1001; i+=2)
    {
        impar[i/2+1]=i;
        par[i/2+1]=i+1;
    }
    while(t--)
    {
        memset(ds, 0, sizeof(ds));
        memset(dp, 0, sizeof(dp));
        fin>>n>>w;
        for(i=1; i<=n; ++i)
            for(j=1; j<=n; ++j)
            {
                fin>>v[i][j];
                dp[i][j]=dp[i-1][j-1]+v[i][j];
                ds[i][j]=ds[i-1][j+1]+v[i][j];
            }
        ans = 0;
        bspar(1,n/2+1);
        bsimpar(max(ans/2,1),n/2+1);
        fout<<ans<<'\n';
    }
}
