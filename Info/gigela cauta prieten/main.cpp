#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("gigela.in");
ofstream fout("gigela.out");

#define mp make_pair
#define f first
#define s second

int v[1010][1010];
int t[1010][1010];
queue <pair<int,int> > q;
int n,m,x,qr;

int main()
{
    int i,j;
    fin>>n>>m>>x>>qr;
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
            fin>>v[i][j];
        v[i][0]=v[i][m+1]=-1;
    }
    for(i=1; i<=m; ++i)
        v[n+1][i]=v[0][i]=-1;
    for(i=1; i<=x; ++i)
    {
        int a,b;
        fin>>a>>b;
        q.push(mp(a,b));
        v[a][b]=i;
        t[a][b]=1;
    }
    int a,b,c,d,k;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    while(!q.empty())
    {
        a = q.front().f;
        b = q.front().s;
        q.pop();
        for(k=0; k<4; ++k)
        {
            c = a + dx[k];
            d = b + dy[k];
            if(v[c][d]==0 || (t[c][d]==t[a][b]+1 && v[a][b]<v[c][d]))
            {
                t[c][d]=t[a][b]+1;
                v[c][d]=v[a][b];
                q.push(mp(c,d));
            }
        }
    }
    while(qr--)
    {
        fin>>a>>b;
        fout<<t[a][b]-1<<' '<<v[a][b]<<'\n';
    }
}
