#include <iostream>
#include <fstream>
#include <queue>
#include <utility>

using namespace std;

ifstream fin("muzeu.in");
ofstream fout("muzeu.out");

#define mp make_pair
#define f first
#define s second

queue <pair<int,int> > q;
int v[300][300];
int i,j,x,y,n,m;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
        {
            char c;
            fin>>c;
            switch(c)
            {
            case '.':
                v[i][j]=-1;
                break;
            case 'P':
                v[i][j]=0;
                q.push(mp(i,j));
                break;
            case '#':
                v[i][j]=-2;
                break;
            }
        }
    while(!q.empty())
    {
        x=q.front().f;
        y=q.front().s;
        q.pop();
        for(i=0; i<4; ++i)
            if(v[x+dx[i]][y+dy[i]]==-1 ||  (v[x+dx[i]][y+dy[i]]>0 && v[x][y]+1<v[x+dx[i]][y+dy[i]]))
            {
                v[x+dx[i]][y+dy[i]]=v[x][y]+1;
                q.push(mp(x+dx[i],y+dy[i]));
            }
    }
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=n; ++j)
            fout<<v[i][j]<<' ';
        fout<<'\n';
    }
}
