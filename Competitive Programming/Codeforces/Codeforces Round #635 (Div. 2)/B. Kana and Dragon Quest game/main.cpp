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
        int x,n,m;
        cin>>x>>n>>m;
        while(x > 20 && n)
        {
            x = x/2 + 10;
            --n;
        }
        while(x > 0 && m)
        {
            x -= 10;
            --m;
        }
        if(x<=0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
