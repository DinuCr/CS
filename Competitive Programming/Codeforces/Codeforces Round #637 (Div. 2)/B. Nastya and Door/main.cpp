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
        int n,k;
        cin>>n>>k;
        vector <int> v;
        int ans = 0;
        int pos = 0;
        for(int i=1; i<=n; ++i)
        {
            int x;
            cin>>x;
            v.pb(x);
        }
        int curr = 0;
        pos = 1;
        for(int i=2; i<v.size(); ++i)
        {
            if(v[i-1]>v[i-2] && v[i-1]>v[i])
                ++curr;
            if(i>=k)
                if(v[i-k+1]>v[i-k] && v[i-k+1]>v[i-k+2])
                    --curr;
            if(i>=k-1 && curr>ans)
                ans = curr,pos = i-k+2;

        }
        cout<<ans+1<<' '<<pos<<'\n';
    }
}