#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long

ifstream fin("");
ofstream fout("");

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	fin.sync_with_stdio(false);
	fout.sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--)
    {
        int n;
        int nr = 0;
        int v[200100];
        memset(v, 0, sizeof(v));
        vector <int> w;
        cin>>n;
        for(int i=1; i<=n; ++i)
        {
            int x;
            cin>>x;
            v[x]++;
            if(v[x]==1)
                nr++,w.pb(x);
        }
        int ans = 0;
        for(auto it:w)
        {
            ans = max(ans, min(nr-1,v[it]));
            ans = max(ans, min(nr, v[it]-1));
        }
        cout<<ans<<'\n';
    }

}
