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
        int n,p,k;
        vector <int> v;
        cin>>n>>p>>k;
        v.pb(0);
        for(int i=1; i<=n; ++i)
        {
            int x;
            cin>>x;
            v.pb(x);
        }
        sort(v.begin(), v.end());
        vector<int> d(v.size(),-1);
        d[0]=p;
        int ans = 0;
        for(int i=1; i<v.size(); ++i)
        {
            if(d[i-1]>=v[i])
                d[i]=d[i-1]-v[i];
            if(i>=k && d[i-k]>=v[i])
                d[i]=max(d[i],d[i-k]-v[i]);
            if(d[i]>=0)
                ans = i;
        }
        cout<<ans<<'\n';
    }
}
