#include <iostream>
#include <fstream>
#include <map>

using namespace std;

ifstream fin("mayonaka.in");
ofstream fout("mayonaka.out");

#define nmax 100010
#define mp make_pair
#define f first
#define s second

int ans[nmax];
map <int,int> h[nmax];

int main()
{
    int n,m,i,x,d,cst,y;
    fin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        fin>>x>>y>>d>>cst;
        if(x+d<=y)
        {
            h[x][d]+=cst;
            ans[x]+=cst;
            h[x+(y-x)/d*d][d]-=cst;
        }
    }
    for(i=1; i<=n; ++i)
    {
        for(auto it:h[i])
            if(i+it.f<=n)
            {
                ans[i+it.f]+=it.s;
                h[i+it.f][it.f]+=it.s;
            }
    }
    for(i=1; i<=n; ++i)
        fout<<ans[i]<<' ';
}
