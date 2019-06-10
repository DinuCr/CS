#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ifstream fin("input.txt");
ofstream fout("output.txt");

int d[1001][101];
int c[1001];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int t;
    fin>>t;
    for(int test_nr = 1; test_nr <= t; ++test_nr)
    {
        vector <pair<int,int> > v[1001];
        int n,m,p,i,j;
        fin>>n>>m>>p;
        for(i=0; i<n; ++i)
            fin>>c[i];
        for(i=1; i<=m; ++i)
        {
            int x,y,cst;
            fin>>x>>y>>cst;
            v[x].pb(mp(y,cst));
            v[y].pb(mp(x,cst));
        }
        for(i=0; i<=n; ++i)
            for(j=0; j<=p; ++j)
                d[i][j]=1e9;
        priority_queue < pair<int,pair<int,int> >, vector <pair<int,pair<int,int> > >, greater <pair<int, pair<int,int> > > >q;
        d[0][0] = 0;
        d[0][1] = c[0];
        q.push(mp(0,mp(0,0))); ///cost, (node, parties)
        q.push(mp(d[0][1],mp(0,1)));
        while(!q.empty())
        {
            int node = q.top().s.f;
            int curr = q.top().s.s;
            int cst = q.top().f;
            q.pop();
            if(cst>d[node][curr])
                continue;
            for(auto it:v[node])
            {
                if(cst + it.s < d[it.f][curr])
                {
                    d[it.f][curr] = cst + it.s;
                    q.push(mp(d[it.f][curr],mp(it.f,curr)));
                }
                if(curr < p && cst + it.s + c[it.f] < d[it.f][curr+1])
                {
                    d[it.f][curr+1] = cst + it.s + c[it.f];
                    q.push(mp(d[it.f][curr+1],mp(it.f,curr+1)));
                }
            }
        }
        int ans = 1e9;
        for(i=0; i<n; ++i)
            ans = min(ans,d[i][p]+d[i][0]);
        fout<<"Case #"<<test_nr<<": "<<ans<<'\n';
    }
}
