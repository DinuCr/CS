#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int n,m,r,i;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n>>m>>r;
    int mn = 1e9;
    int mx = -2;
    for(i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        mn=min(mn,x);
    }
    for(i=1; i<=m; ++i)
    {
        int x;
        cin>>x;
        mx = max(mx,x);
    }
    if(mx>mn)
    cout<<(r/mn)*mx+(r-(r/mn)*mn);
    else
        cout<<r;
}
