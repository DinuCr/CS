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
        vector <ll> v;
        int n;
        cin>>n;
        for(int i=1; i<=n; ++i)
        {
            int x;
            cin>>x;
            v.pb(x);
        }
        ll ans = 0;
        for(int i=1; i<v.size(); ++i)
        {
            if(v[i]<v[i-1])
            {
                ll p = 1;
                ll cnt = 0;
                while(v[i]<v[i-1])
                    v[i]+=p,p<<=1,++cnt;
                v[i]=v[i-1];
                ans = max(ans, cnt);
            }
        }
        cout<<ans<<'\n';
    }
}
