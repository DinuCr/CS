#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("labirint.in");
ofstream fout("labirint.out");

#define nmax 1010
#define mp make_pair
#define f first
#define s second

int v[nmax][nmax];
int d[nmax][nmax],ans;
int k,i,j,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},n,x,y;
int q[1000100][2];

bool lee(int cost)
{
    queue <pair<int,int> > q;
    q.push(mp(1,1));
    d[1][1]=1;

    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            d[i][j]=0;
    while(!q.empty())
    {
        int x = q.front().f;
        int y = q.front().s;
        q.pop();
        if(x==n && y==n)
            return 1;
        for(int i=0; i<4; ++i)
            if(v[x+dx[i]][y+dy[i]]<=cost && d[x+dx[i]][y+dy[i]]==0)
            {
                d[x+dx[i]][y+dy[i]]=1;
                q.push(mp(x+dx[i],y+dy[i]));
            }
    }
    return 0;
}

void bs(int s,int d)
{
    if(s>d)
        return;
    int m = (s+d)/2;
    if(lee(m))
        {
            ans=m;
            bs(s,m-1);
        }
    else
        bs(m+1,d);
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        d[i][0]=d[0][i]=d[n+1][i]=d[i][n+1]=-1;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
        {
            fin>>v[i][j];
        }
    bs(0,100001);
    fout<<max(ans,v[1][1]);
}
