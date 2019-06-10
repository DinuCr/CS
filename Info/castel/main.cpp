#include <iostream>
#include <fstream>
#include <bitset>
#include <deque>
#define pb push_back
using namespace std;
ifstream f("castel.in");
ofstream g("castel.out");
bitset <23000> v;
int w[152][152];
int viz[152][152];
deque <int> q;
int ok,j,i,k,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},n,m,x,y;
int main()
{
    f>>n>>m>>k;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f>>w[i][j];
    for(i=1;i<=n;i++)
        viz[i][0]=viz[i][m+1]=1;
    for(i=1;i<=n;i++)
        viz[0][i]=viz[n+1][i]=1;

    v[k]=1;
    q.pb(k);
    ok=1;
    while(ok)
    {
        ok=0;
        for(i=0;i<q.size();i++)
        {
            x=(q[i]-1)/m+1;
            y=(q[i]-1)%m+1;
            for(k=0;k<4;k++)
            {
                if(!viz[x+dx[k]][y+dy[k]] && v[w[x+dx[k]][y+dy[k]]])
                {
                    viz[x+dx[k]][y+dy[k]]=1;
                    q.pb((x+dx[k]-1)*m+y+dy[k]);
                    ok=1;
                    v[(x+dx[k]-1)*m+y+dy[k]]=1;
                }
            }
        }
    }
    g<<v.count();
}
