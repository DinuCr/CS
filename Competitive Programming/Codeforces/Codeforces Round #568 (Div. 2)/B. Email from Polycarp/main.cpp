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
        int ok = 1;
        string a,b;
        cin>>a>>b;
        int i = 0;
        int j = 0;
        while(i<a.length())
        {
            if(j>=b.length() || a[i]!=b[j])
            {
                cout<<"NO\n";
                ok=0;
                break;
            }
            i++;
            j++;
            if((i<a.length() && a[i]!=a[i-1]) || i==a.length())
            {
                while(j<b.length() && b[j]==b[j-1])
                    ++j;
            }
        }
        if(i==a.length() && j==b.length())
            cout<<"YES\n";
        else
        if(ok)
            cout<<"NO\n";
    }
}
