#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[300001];


int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        for(int i=1; i<=n; ++i)
            cin>>v[i];
        int ok = 0;
        for(int i=1; i<n; ++i)
            if(max(v[i],v[i+1]) - min(v[i],v[i+1]) >= 2)
            {
                cout<<"YES\n"<<i<<' '<<i+1<<'\n';
                ok=1;
                break;
            }
        if(!ok)
            cout<<"NO\n";
    }
}
