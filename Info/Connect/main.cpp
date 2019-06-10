#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int v[255][255];
int dp[255][255];
vector <pair<int,int> > q1;
vector <pair<int,int> > q2;
int ans = -1;
int a,b,c,d;

void bf1(int a,int b)
{
    queue <pair<int,int> > q;
    q.push(mp(a,b));
    dp[a][b]=0;
    while(!q.empty())
    {
        int x = q.front().f;
        int y = q.front().s;
        q.pop();
        q1.push_back(mp(x,y));
        if(x==::c && y==::d)
            ans = 0;
        for(int k=0; k<4; ++k)
        if(v[x+dx[k]][y+dy[k]]==2 && dp[x][y]+1<dp[x+dx[k]][y+dy[k]])
        {
            dp[x+dx[k]][y+dy[k]]=dp[x][y]+1;
            q.push(mp(x+dx[k],y+dy[k]));
        }
    }
}

void bf2(int a,int b)
{
    queue <pair<int,int> > q;
    q.push(mp(a,b));
    dp[a][b]=0;
    while(!q.empty())
    {
        int x = q.front().f;
        int y = q.front().s;
        q.pop();
        q2.push_back(mp(x,y));
        for(int k=0; k<4; ++k)
        if(v[x+dx[k]][y+dy[k]]==2 && dp[x][y]+1<dp[x+dx[k]][y+dy[k]])
        {
            dp[x+dx[k]][y+dy[k]]=dp[x][y]+1;
            q.push(mp(x+dx[k],y+dy[k]));
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int i,j,n;
    cin>>n;
    cin>>a>>b>>c>>d;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
        {
            char x;
            cin>>x;
            v[i][j]=x-'0';
            if(v[i][j]==0)
                v[i][j]=2;
            dp[i][j]=1e9;
        }
    bf1(a,b);
    bf2(c,d);
    if(ans == 0)
    {
        cout<<0;
        return 0;
    }
    ans = 1e9;
    for(auto it1:q1)
        for(auto it2:q2)
        {
            ans = min(ans,(it1.f-it2.f)*(it1.f-it2.f) + (it1.s-it2.s)*(it1.s-it2.s));
        }
    cout<<ans;
}
