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
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        for(int i=0; i<b; ++i)
        {
            s.pb('a'+i);
        }
        for(int i=b; i<n; ++i)
        {
            s.pb(s[i-b]);
        }
        cout<<s<<'\n';
    }
}
