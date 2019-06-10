#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("imperii.in");
ofstream fout("imperii.out");

#define nmax 1010
#define mp make_pair
#define f first
#define s second

queue <pair<int,pair<int,char> > > q;
char ans[nmax][nmax];
int d[nmax][nmax];
int n,m,i,j;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            fin>>ans[i][j];
    q.push(mp(1,mp(1,ans[1][1])));
    q.push(mp(1,mp(m,ans[1][m])));
    q.push(mp(n,mp(1,ans[n][1])));
    q.push(mp(n,mp(m,ans[n][m])));
    d[1][1]=d[1][m]=d[n][1]=d[n][m]=1;
    for(i=1; i<=n; ++i)
        ans[i][0]=ans[i][m+1]='#';
    for(i=1; i<=m; ++i)
        ans[0][i]=ans[n+1][i]='#';
    while(!q.empty())
    {
        int x = q.front().f;
        int y = q.front().s.f;
        char c = q.front().s.s;
        q.pop();
        for(i=0; i<4; ++i)
            if(ans[x+dx[i]][y+dy[i]]!='#' && ans[x+dx[i]][y+dy[i]]!='^')
            {
                if(d[x+dx[i]][y+dy[i]]==0 || d[x][y]+1<d[x+dx[i]][y+dy[i]])
                {
                    q.push(mp(x+dx[i],mp(y+dy[i],ans[x][y])));
                    d[x+dx[i]][y+dy[i]]=d[x][y]+1;
                    ans[x+dx[i]][y+dy[i]]=c;
                }
                else if(d[x][y]+1==d[x+dx[i]][y+dy[i]] && ans[x+dx[i]][y+dy[i]]!=c)
                {
                    q.push(mp(x+dx[i],mp(y+dy[i],d[x][y])));
                    ans[x+dx[i]][y+dy[i]]='^';
                }
            }
    }
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
            if(ans[i][j]=='^')
                fout<<'-';
            else
                fout<<ans[i][j];
        fout<<'\n';
    }
}
