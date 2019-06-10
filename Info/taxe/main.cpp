#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("taxe.in");
ofstream fout("taxe.out");

#define pb push
#define nmax 210
#define mp make_pair
#define f first
#define s second

int v[nmax][nmax];
int d[nmax][nmax];
int dx[3]={-1,0,1};
int dy[3]={-1,-1,-1};
queue <pair<int,int> > q;

int main()
{
    int i,j,n,m,k;
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            fin>>v[i][j];
            if(j==m)
            {
                q.pb(mp(i,j));
                d[i][j]=v[i][j];
            }
            else
                d[i][j]=-1;
        }
    int ans = INT_MAX;
    while(!q.empty())
    {
        int a,b,x,y;
        x=q.front().f;
        y=q.front().s;
        q.pop();
        for(int k=0; k<3; ++k)
            if(dx[k]+x<=n && dx[k]+x>0 && dy[k]+y<=m && dy[k]+y>0 && (d[dx[k]+x][dy[k]+y]>d[x][y]+v[dx[k]+x][dy[k]+y] || d[dx[k]+x][dy[k]+y]==-1))
            {
                d[x+dx[k]][y+dy[k]]=d[x][y]+v[dx[k]+x][dy[k]+y],q.pb(mp(x+dx[k],y+dy[k]));
                if(y+dy[k]==1)
                    ans=min(ans,d[dx[k]+x][dy[k]+y]);
            }
    }
    fout<<ans;
}
