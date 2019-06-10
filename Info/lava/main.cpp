#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define nmax 1100
#define mp make_pair
#define f first
#define s second

int v[nmax][nmax];
int d[nmax][nmax];
queue <pair<int,int> > q;
int n,m,i,j,x,y,nr,k;

int dy[12]={-1,-2,-1,0,0,1,1,2,1,0,0,1};
int dx[12]={0,0,-1,-1,-2,-1,0,0,1,1,2,1};

int main()
{
    char c;
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            fin>>c;
            switch(c)
            {
            case '.':
                v[i][j]=0;
                break;
            case '#':
                v[i][j]=1;
                break;
            }
            d[i][j]=1000000000;
        }
    q.push(mp(1,1));
    d[1][1]=1;
    while(!q.empty())
    {
        x = q.front().f;
        y = q.front().s;
        nr=d[x][y];
        q.pop();
        for(k=0; k<12; ++k)
        if(x + dx[k]>0 && x+dx[k] <=n && y+dy[k]>0 && y+dy[k]<=m && v[x+dx[k]][y+dy[k]]==0)
        {
            if(d[x+dx[k]][y+dy[k]]>nr+1)
            {
                q.push(mp(x+dx[k],y+dy[k]));
                d[x+dx[k]][y+dy[k]]=nr+1;
            }
        }
    }

    fout<<d[n][m]-1;
}
