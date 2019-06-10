#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[101],w[101],q[101][101],n,m,h,i,j;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n>>m>>h;
    for(i=1; i<=m; ++i)
        cin>>v[i];
    for(i=1; i<=n; ++i)
        cin>>w[i];
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            cin>>q[i][j];
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
            cout<<min(v[j],w[i])*q[i][j]<<' ';
        cout<<'\n';
    }
}
