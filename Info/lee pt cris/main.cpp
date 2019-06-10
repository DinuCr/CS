#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

char v[105][105];
int n,m,q1,i,j;
queue <pair<int,int> > q;
int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,-1,1,-1,1};

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>q1;

    for(i=1; i<=5; ++i)
        for(j=1; j<=5; ++j)
            v[i][j]='_';
    while(q1--)
    {
        int x,y;
        cin>>x>>y;
        v[x][y]='X';
    }
    q.push(mp(1,1));
    v[1][1]='1';
    int a = 1;
    while(!q.empty() && a)
    {
        int ok = false;
        int x = q.front().f;
        int y = q.front().s;
        q.pop();
        for(int k=0; k<8; ++k)
            if(v[x+dx[k]][y+dy[k]]=='_')
                {
                    v[x+dx[k]][y+dy[k]]=v[x][y]+1;
                    ok = 1;
                    if(x+dx[k]==5 && y+dy[k]==5)
                        a=0;
                    q.push(mp(x+dx[k],y+dy[k]));
                }
        for(i=1; i<=5 ; ++i)
        {
            for(j=1; j<=5; ++j)
                cout<<v[i][j]<<' ';
            cout<<endl;
        }
        cout<<endl;
    }
}
