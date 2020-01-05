#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

string v[100],w[100];

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int n,m,q;

	cin>>n>>m;
	for(int i=1; i<=n; ++i)
        cin>>v[i];
    for(int j=1; j<=m; ++j)
        cin>>w[j];
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        int a = (x-1)%n +1;
        int b = (x-1)%m +1;
        cout<<v[a]<<w[b]<<'\n';
    }
}
