#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("ciclu.in");
ofstream fout("ciclu.out");

#define nmax 1010
#define mp make_pair
#define f first
#define s second

vector <pair<int, pair<int,int> > > v[nmax];
int cnt [nmax*4];
long long d[nmax];
int used[nmax];
int w[nmax];
int n,m,i;
int ans;

bool bellman(int x,int curr)
{
    queue <int> q;
    for(int i=1; i<=n; ++i)
    {
        d[i]=(int)1e8+100;
        used[i]=0;
    }
    for(int i=1; i<=m; ++i)
        cnt[i]=0;
    q.push(x);
    used[x]=1;
    d[x]=0;
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        w[nod]=1;
        used[nod]=0;
        for(int i=0; i<v[nod].size(); ++i)
            if(d[v[nod][i].f]>d[nod]+v[nod][i].s.f-curr)
            {
                d[v[nod][i].f]=d[nod]+v[nod][i].s.f-curr;
                ++cnt[v[nod][i].s.s];
                if(cnt[v[nod][i].s.s]==n)
                    return 1;
                if(!used[v[nod][i].f])
                {
                    q.push(v[nod][i].f);
                    used[v[nod][i].f]=1;
                }
            }
    }
    return 0;
}

bool check(int curr)
{
    int ok=0;
    for(i=1; i<=n; ++i)
        w[i]=0;
    for(i=1; i<=n; ++i)
        if(!w[i])
        {
            if(bellman(i,curr))
                return 1;
        }
    return 0;
}


void bs(int l,int r)
{
    if(l>r)
        return;
    int m = (l+r)/2;
    if(check(m))
    {
        ans=m-1;
        bs(l,m-1);
    }
    else
        bs(m+1,r);
}

int main()
{
    fin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        int a,b,c;
        fin>>a>>b>>c;
        v[a].push_back(mp(b,mp(c*100,i)));
    }
    bs(0,10000000);
    fout<<(double)ans/100;
}
