#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("fractii2.in");
ofstream fout("fractii2.out");

#define nmax 2010

inline int mod(int x)
{
    if(x>=100003)
        return x%100003;
    return x;
}

int d[nmax][nmax];
int p,n,i,j,k,ans;

int main()
{
    fin>>p>>n;
    if(p==1)
    {
        for(i=1; i<n; ++i)
            fout<<i<<' ';
        fout<<n-1;
    }
    else
    {

        d[2][1]=1;
        for(i=2; i<=n; ++i)
            for(j=1; j<=i/2; ++j)
            {
                for(k=1; k<=(j<<1); ++k)
                    if(i+k<n)
                    {
                         d[i+k][k]=mod(d[i+k][k]+d[i][j]);
                    }
                    else
                    {
                        ans=mod(ans+d[i][j]);
                        break;
                    }
            }
        fout<<ans;
    }
}
