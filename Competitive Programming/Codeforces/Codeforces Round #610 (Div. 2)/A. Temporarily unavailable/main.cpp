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
        int x,y,c,r;
        cin>>x>>y>>c>>r;
        int a,b;
        a = c-r;
        b = c+r;
        if(y<x)
            swap(x,y);
        int ans = 0;
        if(y<a || b<x)
            ans=0;
        else
        {
            ans = min(b,y)-max(x,a);
            if(ans<0)
                ans=0;
        }
        cout<<(y-x)-ans<<'\n';
    }
}
