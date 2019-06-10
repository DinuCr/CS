#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("ubuntzei.in");
ofstream fout("ubuntzei.out");

#define mp make_pair
#define f first
#define s second
#define nmax 2010

vector <pair<int,int> >v[nmax];
int c[20];
priority_queue <pair<int,int> , vector <pair<int,int> >, greater<pair<int,int> > >q;
int w[nmax],n,k,m;
int d[(1<<16)+10][18];
int dist[20][20];

void dijkstra(int x)
{
    int i;
    q.push(mp(0,c[x]));
    for(i=1; i<=n; ++i)
        w[i]=1e9;
    w[c[x]]=0;
    int nod;
    while(q.size())
    {
        nod = q.top().s;
        if(q.top().f!=w[nod])
        {
            q.pop();
            continue;
        }
        q.pop();
        for(auto it:v[nod])
            if(w[it.f]>w[nod]+it.s)
            {
                w[it.f]=w[nod]+it.s;
                q.push(mp(w[it.f],it.f));
            }
    }
    for(int i=0; i<=k; ++i)
    {
        dist[x][i]=w[c[i]];
        if(x==0 && i!=x && i!=k)
            d[1<<(i-1)][i]=w[c[i]];
    }
}

int main()
{
    int i,j;
    fin>>n>>m;
    fin>>k;
    c[0]=1;
    for(i=1; i<=k; ++i)
        fin>>c[i];
    c[++k]=n;
    int a,b,z;
    while(m--)
    {
        fin>>a>>b>>z;
        v[a].push_back(mp(b,z));
        v[b].push_back(mp(a,z));
    }
    int lim = (1<<(k-1));
    for(i=1; i<lim ; ++i)
        for(j=1; j<k; ++j)
            d[i][j]=1e9;
    for(i=0; i<=k; ++i)
        dijkstra(i);
    --k;
    for(i=1; i<lim; ++i)
    {
        for(j=1; j<=k; ++j)
            if(i & (1<<(j-1)))
            {
                for(a=1; a<=k; ++a)
                if((i & (1<<(a-1))) && a!=j)
                {
                    d[i][j]=min(d[i][j],d[i-(1<<(j-1))][a]+dist[a][j]);
                }
            }
    }

    if(k==0)
    {
        fout<<dist[0][k+1];
    	return 0;
	}
    int ans = 1e9;
    for(i=1; i<=k; ++i)
        ans=min(ans,d[lim-1][i]+dist[i][k+1]);
    fout<<ans;
}
