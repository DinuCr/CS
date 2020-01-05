#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--)
    {
        int n,m;
        int v[(int)1e5+10];
        int w[(int)1e5+10];
        int pos[(int)1e5+10];
        cin>>n>>m;
        for(int i=1; i<=n; ++i)
            cin>>v[i];
        for(int i=1; i<=m; ++i)
            cin>>w[i];
        ll ans = m;
        for(int i=1; i<=n; ++i)
            pos[v[i]]=i;
        int down = 0;
        for(int i=1; i<=m; ++i)
        {
            down=max(down, i);
            if(pos[w[i]]>down)
            {
                down = pos[w[i]];
                ans+=(pos[w[i]]-i)*2;
            }
        }
        cout<<ans<<'\n';
    }
}
