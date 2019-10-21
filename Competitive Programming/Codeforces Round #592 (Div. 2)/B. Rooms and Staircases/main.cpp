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

    int t,n;

    cin>>t;
    while(t--)
    {
        cin>>n;
        int mn = n+1;
        int mx = 0;
        for(int i=1; i<=n; ++i)
        {
            char c;
            cin>>c;
            if(c=='1')
                mx=max(mx,i),mn=min(mn,i);
        }
        int ans = max(mx*2,max(n,(n-mn+1)*2));
        cout<<ans<<'\n';
    }
}
