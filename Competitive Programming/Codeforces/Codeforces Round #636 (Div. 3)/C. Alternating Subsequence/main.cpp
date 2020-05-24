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


	ll t;
	cin>>t;
	while(t--)
    {
        ll n;
        cin>>n;
        ll v[(ll)2e5+10];
        for(ll i=1; i<=n; ++i)
            cin>>v[i];
        ll sum = 0;
        for(ll i=1; i<=n; ++i)
        {
            ll mx = v[i];
            int j;
            for(j=i+1; j<=n; ++j)
                if(v[i]*v[j]>0)
                    mx = max(mx, v[j]);
                else break;
            sum += mx;
            i = j-1;
        }
        cout<<sum<<'\n';
    }
}
