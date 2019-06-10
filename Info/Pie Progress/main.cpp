#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;

ifstream fin("pie.in");
ofstream fout("pie.out");

#define nmax 310

int v[nmax][nmax];
int t,i,j,n,m;

int main()
{
    fin>>t;
    for(int k=1; k<=t; ++k)
    {
        fin>>n>>m;
        for(i=1; i<=n; ++i)
        {
            for(j=1; j<=m; ++j)
                fin>>v[i][j];
            sort(v[i]+1,v[i]+m+1);
            int last=0;
            for(j=1; j<=m; ++j)
            {
                v[i][j]+=(j*j)-last;
                last=j*j;
            }
        }
        priority_queue<int,vector<int>, greater<int> >q;
        long long ans = 0;
        for(i=1; i<=n; ++i)
        {
            for(j=1; j<=m; ++j)
                q.push(v[i][j]);
            ans=1LL*ans+1LL*q.top();
            q.pop();
        }
        fout<<"Case #"<<k<<": "<<ans<<'\n';
    }
}
