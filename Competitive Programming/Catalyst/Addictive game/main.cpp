#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ifstream fin("level5-4.in");
ofstream fout("output.out");

const int nmax = 1e3+10;

int n,m;
vector <int> v[(int)1e6];
int connected[(int)1e6];

int board[nmax][nmax];

int w[nmax][nmax];

pair<int,int> toPos(int x)
{
    int a = (x-1)/m + 1;
    int b = x - (a-1) * m;
    return mp(a,b);
}

void del(vector <pair<int,int> > &v)
{
    for(auto it:v)
        board[it.f][it.s]=0;
    v.clear();
}

int lee(int start, int finish)
{
    int a = toPos(start).f;
    int b = toPos(start).s;

    int x = toPos(finish).f;
    int y = toPos(finish).s;

    queue <pair<int,int> > q;

    q.push(mp(a,b));

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            w[i][j]=board[i][j];

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    w[a][b]=1;
    w[x][y]=0;

    while(!q.empty())
    {
        int a = q.front().f;
        int b = q.front().s;
        q.pop();
        if(a<=0 || b<=0 || a>n || b>m)
            continue;
        if(a==x && b==y)
            return 2;
        for(int i=0; i<4; ++i)
            if(w[a+dx[i]][b+dy[i]]==0)
            {
                w[a+dx[i]][b+dy[i]] = w[a][b]+1;
                q.push(mp(a+dx[i], b+dy[i]));
            }
    }

    return 3;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

    int t;
    fin>>t;


    for(int test = 1; test<=t; ++test)
    {

        for(int i=1; i<1e6; ++i)
            v[i].clear();
        memset(board, 0, sizeof(board));
        memset(connected, 0, sizeof(connected));

        fin>>n>>m;

        int q;

        fin>>q;


        while(q--)
        {
            int a,b;
            fin>>a>>b;
            v[b].pb(a);
        }

        int colors = 0;

        for(int i=1; v[i].size()!=0; ++i)
        {
            colors = i;

            pair<int,int> x = toPos(v[i][0]);
            pair<int,int> y = toPos(v[i][1]);

            board[x.f][x.s] = i;
            board[y.f][y.s] = i;
        }

        fin>>q;

        while(q--)
        {
            int color, sp, len;
            char c;
            fin>>color;
            fin>>sp;
            fin>>len;

            int x = toPos(sp).f;
            int y = toPos(sp).s;

            vector <pair<int,int> > st;

            int ok = 0;

            for(int j=1; j<=len; ++j)
            {
                if(j>1)
                    st.pb(mp(x,y));

                fin>>c;
                if(c=='N')
                    --x;
                else if(c=='S')
                    ++x;
                else if(c=='E')
                    ++y;
                else
                    --y;
                if(x<=0 || x>n || y<=0 || y>m)
                {
                    del(st);
                    ok=j;
                    break;
                }
                if(j<len && board[x][y]!=0)
                {

                    del(st);
                    ok=j;
                    break;
                }
                else
                if(j==len)
                {
                    if(board[x][y]!=color || (x==toPos(sp).f && y==toPos(sp).s))
                    {
                        del(st);
                        ok=j;
                    }
                    break;
                }
                board[x][y]=-1;
            }
            if(ok!=0)
                for(int j = ok+1; j<=len; ++j)
                    fin>>c;
            else
                connected[color]=1;
        }

        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                if(board[i][j]!=0)
                    board[i][j]=-1;

        for(int i=1; i<=colors; ++i)
        {
            if(connected[i]==1)
                fout<<1<<' ';
            else
            {
                int ok = lee(v[i][0],v[i][1]);
                fout<<ok<<' ';
            }
        }

    }
}
