#include <iostream>
#include <fstream>

using namespace std;

ifstream f("peri.in");
ofstream g("peri.out");

#define nmax 260

int h[nmax][nmax],v[nmax][nmax],n,m,i,j,k,nr,mx,curr,sum,ans;

int main()
{
    f>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            f>>v[i][j];
            if(!v[i][j])
                --v[i][j];
            h[i][j]=v[i][j]+h[i-1][j];
        }
    mx=-100000;
    ans=0;
    curr=0;
    for(i=1; i<=n; ++i)
        for(j=i+1; j<=n; ++j)
        {
            curr=h[j][1]-h[i-1][1];
            nr=1;
            for(k=2; k<=m; ++k)
            {
                sum=h[j][k]-h[i-1][k];
                if(mx < curr + sum)
                {
                    ans=nr;
                    mx=curr+sum;
                }
                else
                if(mx==curr+sum)
                    ans+=nr;

                curr+=v[i][k]+v[j][k];

                if(curr<sum)
                {
                    curr=sum;
                    nr=1;
                }
                else
                if(curr==sum)
                    ++nr;
            }
        }
    g<<mx<<' '<<ans;
}
