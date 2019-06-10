#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("partii.in");
ofstream fout("partii.out");

#define nmax 1010

int v[nmax][nmax];
int d1[nmax][nmax];
int d2[nmax][nmax];
int d3[nmax][nmax];
int d4[nmax][nmax];
int n,m,i,j;

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            fin>>v[i][j];
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            if(v[i][j]>v[i-1][j])
                d1[i][j]=d1[i-1][j]+1;
            else
                d1[i][j]=1;
        }
    for(i=1; i<=n; ++i)
        for(j=m; j>0; --j)
        {
            if(v[i][j]>v[i][j+1])
                d2[i][j]=d2[i][j+1]+1;
            else
                d2[i][j]=1;
        }
    for(i=n; i>0; --i)
        for(j=1; j<=m; ++j)
        {
            if(v[i][j]>v[i+1][j])
                d3[i][j]=d3[i+1][j]+1;
            else
                d3[i][j]=1;
        }
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            if(v[i][j]>v[i][j-1])
                d4[i][j]=d4[i][j-1]+1;
            else
                d4[i][j]=1;
        }
    int mx = 0;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            mx=max(mx,d1[i][j]+d2[i][j]+d3[i][j]+d4[i][j]);
    fout<<mx-3;
}
