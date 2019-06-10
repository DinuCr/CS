9gag
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define nmax 110
//ifstream f("in.in");

priority_queue < pair <int,int> , vector < pair <int,int> > , greater < pair <int,int> > > h;
vector <pair<int,int> > v[nmax];
int d[nmax];
int fa[nmax];
int ans[nmax];
int n,m,k,t,i,a,b,cost,mn,nod;

void remember(int x,int y)
{
    k=0;
    while(x)
    {
        ans[++k]=x;
        x=fa[x];
    }
    for(int i=1; i<=k/2; ++i)
        swap(ans[i],ans[k-i+1]);
    while(fa[y])
    {
        ans[++k]=y;
        y=fa[y];
    }
}

void minim(int a,int b,int cost)
{
    for(int i=0; i<v[a].size(); ++i)
        if(v[a][i].s==b)
        {
            if(v[a][i].f<=cost)
                return;
            v[a][i].f=cost;
            return;
        }
    v[a].push_back(mp(cost,b));
}

int main()
{
    cin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        cin>>a>>b>>cost;
        minim(a,b,cost);
        minim(b,a,cost);
    }
    mn=1000000000;
    for(t=1; t<=n; t++)
    {
        for(i=1; i<=n; ++i)
            d[i]=1000000000;
        d[t]=0;
        fa[t]=0;
        h.push(mp(0,t));
        while(h.size())
        {
            nod=h.top().s;
            h.pop();
            for(i=0; i<v[nod].size(); ++i)
            {
                int y=v[nod][i].s;
                if(d[v[nod][i].s]>d[nod]+v[nod][i].f)
                {
                    d[v[nod][i].s]=d[nod]+v[nod][i].f;
                    fa[v[nod][i].s]=nod;
                    h.push(mp(d[v[nod][i].s],v[nod][i].s));
                }
                else
                if(fa[nod]!=v[nod][i].s && nod!=fa[v[nod][i].s] && d[nod]+d[v[nod][i].s]+v[nod][i].f<mn)
                {
                    mn=d[nod]+d[v[nod][i].s]+v[nod][i].f;
                    remember(nod,v[nod][i].s);
                }
            }
        }
    }
    if(mn!=1000000000)
    for(i=1; i<=k; ++i)
        cout<<ans[i]<<' ';
    else
        cout<<"No solution.";
}
