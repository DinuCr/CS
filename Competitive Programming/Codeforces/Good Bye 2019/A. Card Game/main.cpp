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
        int n,a,b;
        cin>>n>>a>>b;
        int mx1 = 0;
        int mx2 = 0;
        for(int i=1; i<=a; ++i)
        {
            int x;
            cin>>x;
            mx1 = max(mx1, x);
        }
        for(int i=1; i<=b; ++i)
        {
            int x;
            cin>>x;
            mx2 = max(mx2, x);
        }
        if(mx1>mx2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
