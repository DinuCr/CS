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
        cin>>n;
        if(n/2%2==1)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            ll sum = 0;
            for(int i=2; i<=n; i+=2)
                cout<<i<<' ',sum+=i;

            for(int i=1; i<n-1; i+=2)
                cout<<i<<' ',sum-=i;
            cout<<sum<<'\n';
        }
    }
}
