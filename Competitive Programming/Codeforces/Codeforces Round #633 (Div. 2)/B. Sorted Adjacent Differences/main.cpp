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
        vector <int> v;
        int n;
        cin>>n;
        for(int i=1; i<=n; ++i)
        {
            int x;
            cin>>x;
            v.pb(x);
        }
        sort(v.begin(), v.end());
        vector <int> w;
        int a = 1;
        int b = n-1;
        w.pb(v[0]);

        while(a<b)
        {
            if(abs(w.back()-v[a]) > abs(v[b]-w.back()))
            {
                w.pb(v[a]);
                ++a;
            }
            else
            {
                w.pb(v[b]);
                b--;
            }
        }
        w.pb(v[a]);
        reverse(w.begin(),w.end());
        for(auto it:w)
            cout<<it<<' ';
        cout<<'\n';
    }

}
