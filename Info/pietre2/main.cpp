#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("pietre2.in");
ofstream fout("pietre2.out");

#define f first
#define s second
#define mp make_pair

queue <pair<int,int> >q;
int v[110][110];
int d[110][110];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans,nr,n,i,j,x,y;

void bf(int x,int y)
{
    if(d[x][y]==0)
    {
        int a,b,k;
        q.push(mp(x,y));
        while(!q.empty())
        {
            a = q.front().f;
            b = q.front().s;
            nr=max(nr,d[a][b]);
            q.pop();
            for(k = 0; k<4; ++k)
                if(v[a+dx[k]][b+dy[k]]==v[a][b]+1 && d[a+dx[k]][b+dy[k]]<d[a][b]+1)
                {
                    d[a+dx[k]][b+dy[k]]=d[a][b]+1;
                    q.push(mp(a+dx[k],b+dy[k]));
                }
        }
    }
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            fin>>v[i][j];
    for(i=1; i<=n; ++i)
    {
        nr = 0;
        bf(1,i);
        if(nr>ans)
        {
            ans = nr;
            x=1;
            y=i;
        }
        nr=0;
        bf(n,i);
        if(nr>ans)
        {
            ans = nr;
            x=n;
            y=i;
        }

        nr=0;
        bf(i,1);
        if(nr>ans)
        {
            ans = nr;
            x=i;
            y=1;
        }

        nr=0;
        bf(i,n);
        if(nr>ans)
        {
            ans = nr;
            x=i;
            y=n;
        }
    }
    cout<<ans<<'\n'<<x<<' '<<y;
}
