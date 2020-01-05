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
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b+c+1 || b>a+c+1 || c>a+b+1)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
}
