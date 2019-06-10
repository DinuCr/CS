#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("elimin.in");
ofstream fout("elimin.out");

short v[1010][1010];
short w[1010][1010];
int sum[1010];
int q[30];
int n,m,r,c,i,j,k,kmax,ans,curr;

int main()
{
    fin>>n>>m>>r>>c;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            fin>>v[i][j];
    if(m<n)
    {
        for(i=1; i<=n; ++i)
            for(j=1; j<=m; ++j)
                w[j][i]=v[i][j];
        swap(r,c);
        swap(n,m);
    }
    else
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            w[i][j]=v[i][j];
    ans=-1000000000;
    int p[20];
    p[0]=1;
    for(i=1; i<=n; ++i)
        p[i]=p[i-1]*2;
    kmax=p[n];
    for(i=0; i<kmax; ++i)
    {
        int nr = 0;
        for(j=0; j<n; ++j)
            q[j]=0;
        for(j=0; j<n; ++j)
            if(p[j] & i)
            {
                ++nr;
                q[j+1]=1;
            }
        if(nr == r)
        {
            curr=0;

            for(j=1; j<=m; ++j)
                sum[j]=0;

            for(j=1; j<=n; ++j)
                if(!q[j])
                for(k=1; k<=m; ++k)
                    {
                        sum[k]+=w[j][k];
                        curr+=w[j][k];
                    }
            sort(sum+1,sum+m+1);
            for(j=1; j<=c; ++j)
                curr-=sum[j];
            ans=max(ans,curr);
        }
    }
    fout<<ans;
}
