#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

vector <int> h[501];
int v[501][501];
int w[501][501];


void del(pair<int,int> a,pair<int,int> b)
{
    for(int i=0; i<h[a.s].size(); ++i)
        if(h[a.s][i]==a.f)
        {
            swap(h[a.s][i],h[a.s][h[a.s].size()-1]);
            h[a.s].pop_back();
            break;
        }
    for(int i=0; i<h[b.s].size(); ++i)
        if(h[b.s][i]==b.f)
        {
            swap(h[b.s][i],h[b.s][h[b.s].size()-1]);
            h[b.s].pop_back();
            break;
        }
}

int find_p(pair<int,int> a,pair<int,int> b)
{
    for(int i=0; i<h[a.s].size(); ++i)
        for(int j=0; j<h[b.s].size(); ++j)
            if(h[a.s][i]==h[b.s][j])
            {
                v[h[a.s][i]][a.s]=!v[h[a.s][i]][a.s];
                v[h[b.s][j]][b.s]=!v[h[b.s][j]][b.s];
                del(mp(h[a.s][i],a.s),mp(h[b.s][j],b.s));
                return 1;
            }
    return 0;

}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    int i,j;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            cin>>v[i][j];
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            cin>>w[i][j];
        }
    pair<int,int> a,b;
    int ok;
    for(i=1; i<n; ++i)
    {
        vector <int> curr;
        for(j=1; j<=m; ++j)
            if(v[i][j]!=w[i][j])
                curr.pb(j);
        if(curr.size()%2==1)
        {
            cout<<"No";
            return 0;
        }
        for(j=0; j<curr.size(); j+=2)
        {
            a = mp(i,curr[j]);
            b = mp(i,curr[j+1]);
            v[a.f][a.s]=!v[a.f][a.s];
            v[b.f][b.s]=!v[b.f][b.s];
            v[a.f+1][a.s]=!v[a.f+1][a.s];
            v[b.f+1][b.s]=!v[b.f+1][b.s];
        }
    }
    for(j=1; j<=m; ++j)
        if(v[i][j]!=w[i][j])
        {
    cout<<"No";
            return 0;

        }
    cout<<"Yes";
}
