#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ll v[100100][2],d[100100][2],n,i,ans;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i][0];
    for(i=1; i<=n; ++i)
        cin>>v[i][1];
    d[1][0]=v[1][0];
    d[1][1]=v[1][1];
    ans = max(d[1][0],d[1][1]);
    for(i=2; i<=n; ++i)
    {
        d[i][0]=max(d[i-1][0],max(d[i-1][1]+v[i][0],d[i-2][1]+v[i][0]));
        d[i][1]=max(d[i-1][1],max(d[i-1][0]+v[i][1],d[i-1][0]+v[i][1]));
        ans = max(ans,max(d[i][0],d[i][1]));
    }
    cout<<ans;
}
