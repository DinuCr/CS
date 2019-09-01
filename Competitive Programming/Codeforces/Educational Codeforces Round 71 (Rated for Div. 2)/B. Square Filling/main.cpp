#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[110][110];
int w[110][110];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n,m,i,j;

    cin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            cin>>v[i][j];
    vector <pair<int,int> > q;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(v[i][j] && v[i+1][j] && v[i][j+1] && v[i+1][j+1] && i<n && j<m)
            {
                q.pb(mp(i,j));
                w[i][j]=w[i+1][j]=w[i][j+1]=w[i+1][j+1]=1;
            }
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(w[i][j]!=v[i][j])
            {
                cout<<-1;
                return 0;
            }
    cout<<q.size()<<'\n';
    for(auto it:q)
        cout<<it.f<<' '<<it.s<<'\n';
}
