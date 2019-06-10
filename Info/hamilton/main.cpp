#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("hamilton.in");
ofstream fout("hamilton.out");


#define nmax 20
#define inf 1000000000

inline int po(int n)
{
    return (1<<n);
}

int d[(1<<nmax)][nmax];
int cost[nmax][nmax];
int n,m,i,a,b,c,j,ans;
vector <int> v[nmax];

int main()
{
    fin>>n>>m;
    for(i=0; i<n; ++i)
        for(j=0; j<n; ++j)
            cost[i][j]=inf;
    for(i=1; i<=m; ++i)
    {
        fin>>a>>b>>c;
        v[b].push_back(a);
        if(cost[a][b]==0)
            cost[a][b]=c;
        else
            cost[a][b]=min(cost[a][b],c);
    }
    for(j=1; j<po(n); ++j)
        for(i=0; i<n; ++i)
            d[j][i]=inf;
    d[1][0]=0;
    int x=po(n);
    for(j=1; j<po(n); ++j)
    {
        for(i=0; i<n; ++i)
        {
            if(j & po(i))
                for(int k=0; k<v[i].size(); ++k)
                    if(j & po(v[i][k]))
                        d[j][i]=min(d[j][i], d[j ^ (po(i))][v[i][k]] + cost[v[i][k]][i]);
        }
    }
    ans=inf;
    for(i=0; i<v[0].size(); ++i)
        ans=min(ans,d[x-1][v[0][i]] + cost[v[0][i]][0]);

    if(ans!=inf)
        fout<<ans;
    else
        fout<<"Nu exista solutie";
}
