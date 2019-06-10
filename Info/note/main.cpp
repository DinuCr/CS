#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("note.in");
ofstream fout("note.out");

#define nmax 1030

int d[nmax][nmax];
int v[nmax][nmax];
int w[nmax];
int i,j,n,k,p;

int main()
{
    fin>>n>>p;
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=p; ++j)
        {
            int x;
            fin>>x;
            v[j][x]=1;
        }
    }
    fin>>k;
    for(i=1; i<=k; ++i)
        fin>>w[i];
    for(i=0; i<=p; ++i)
        for(j=0; j<=k; ++j)
        {
            if(i>0 && j>0)
                d[i][j]=min(d[i-1][j]+1,min(d[i][j-1]+1,d[i-1][j-1]+!v[i][w[j]]));
            else
            if(i>0)
            {
                d[i][j]=d[i-1][j]+1;
            }
            else
            if(j>0)
            {
                d[i][j]=d[i][j-1]+1;
            }
            else
            d[i][j]=0;
        }
    fout<<d[p][k];
}
