#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("xcmmdc.in");
ofstream fout("xcmmdc.out");

#define nmax 1005

int ans[nmax];
int d[11][nmax][nmax];
int n,m,k,q,i,j,l;

inline int gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main()
{
    fin>>n>>m>>k>>q;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            fin>>d[0][i][j];
    for(l = 1; (1<<l)<=min(n,m); ++l)
        for(i=1; i<=n; ++i)
            if(i+(l<<1)-1<=n)
            {
                for(j=1; j<=m; ++j)
                    if(j+(1<<l)-1<=m)
                    {
                        d[l][i][j]=gcd(d[l-1][i][j],gcd(d[l-1][i+(1<<(l-1))][j],gcd(d[l-1][i][j+(1<<(l-1))],d[l-1][i+(1<<(l-1))][j+(1<<(l-1))])));
                    }
                    else
                        break;
            }
            else
                break;

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(d[0][i][j]%k==0)
            {
                int lim = min(n-i+1,m-j+1);
                int step;
                for(step = 1; step<=lim; step<<=1);
                int mn = lim;
                int mx = 0;
                int step2 = step;
                int l = step;
                for( ; step; step>>=1)
                {
                    l=0;
                    while((1<<(l+1)<=mx+step))
                        ++l;
                    if(mx+step<=lim && gcd(d[l][i][j],gcd(d[l][i+mx+step-(1<<l)][j],gcd(d[l][i][j+mx+step-(1<<l)],d[l][i+mx+step-(1<<l)][j+mx+step-(1<<l)])))>=k)
                        mx+=step;
                }
                step = step2;
                l=1;
                for( ; step; step>>=1)
                {
                    l=0;
                    while((1<<(l+1)<=mn-step))
                        ++l;
                    if(mn-step>=1 && gcd(d[l][i][j],gcd(d[l][i+mn-step-(1<<l)][j],gcd(d[l][i][j+mn-step-(1<<l)],d[l][i+mn-step-(1<<l)][j+mn-step-(1<<l)])))<=k)
                        mn-=step;
                }
                if(mn<mx)
                    ++ans[mn],--ans[mx+1];
                else if(mn==mx)
                {
                    l=0;
                    while((1<<(l+1)<=mn))
                        ++l;
                    if(gcd(d[l][i][j],gcd(d[l][i+mn-(1<<l)][j],gcd(d[l][i][j+mn-(1<<l)],d[l][i+mn-(1<<l)][j+mn-(1<<l)])))==k)
                        ++ans[mn],--ans[mn+1];
                }
            }
    for(i=1; i<=min(n,m); ++i)
        ans[i]+=ans[i-1];
    while(q--)
    {
        fin>>l;
        fout<<ans[l]<<'\n';
    }
}
