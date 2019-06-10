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

    int n,t,i;

    cin>>n>>t;
    int mn = 1e9;
    int ans = 0;
    for(i=1; i<=n; ++i)
    {
        int x,y;
        cin>>x>>y;
        int curr;
        if(t>x)
            curr = (t-x)/y*y+x;
        else
            curr = x;
        if(curr<t)
            curr+=y;
        if(curr<mn)
            mn=curr,ans=i;
    }
    cout<<ans;
}
