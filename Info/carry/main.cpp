#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("carry.in");
ofstream fout("carry.out");

const int modulo = 30211;

#define nmax 100010

int d[nmax][105];
int b[nmax][105];
int n,k,i,j;
int v[nmax];


inline int mod (int x)
{
    if(x>=modulo)
        return x%modulo;
    return x;
}

int main()
{
    fin>>n>>k;
    for(i=n; i>0; --i)
    {
        char x;
        fin>>x;
        v[i]=x-'0';
    }
    d[0][0]=1;
    for(i=1; i<=n; ++i)
        for(j=0; j<=k; ++j)
        {
            if(i<n)
            {
                d[i][j]+=d[i-1][j]*(10-v[i]);
                d[i][j]+=b[i-1][j]*(10-v[i]-1);
                if(j>0)
                {
                    b[i][j]+=b[i-1][j-1]*(v[i]+1);
                    b[i][j]+=d[i-1][j-1]*(v[i]);
                }
            }
            else
            {
                d[i][j]+=d[i-1][j]*(10-v[i]-1);
                d[i][j]+=b[i-1][j]*(max(10-v[i]-2,0));
                if(j>0)
                {
                    b[i][j]+=b[i-1][j-1]*(min(v[i]+1,9));
                    b[i][j]+=d[i-1][j-1]*(v[i]);
                }
            }
            d[i][j]=mod(d[i][j]);
            b[i][j]=mod(b[i][j]);
        }
    fout<<mod(d[n][k]+b[n][k]);
}
