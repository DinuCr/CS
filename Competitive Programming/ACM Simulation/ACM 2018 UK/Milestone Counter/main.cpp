#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ll v[1001],w[1001];
ll i,j,n,m;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>m>>n;

    for(i=1; i<=m; ++i)
        cin>>v[i];
    for(j=1; j<=n; ++j)
        cin>>w[j];

    set <ll> ans;

    for(i=1; i<=n-m+1; ++i)
    {
        long double speed = (double)(w[i+1]-w[i])/(v[2]-v[1]);
        int ok=1;
        for(j=2; j<m; ++j)
        {
            if((double)(w[i+j]-w[i+j-1])/(v[j+1]-v[j])!=speed)
            {
                ok=0;
                break;
            }
        }
        if(ok)
        ans.insert(w[i+1]-w[i]);
    }
    cout<<ans.size()<<'\n';
    for(auto it:ans)
        cout<<it<<' ';
}
