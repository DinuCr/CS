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

    int n,i;

    cin>>n;
    int ans = 0;
    for(i=1; i<=n; ++i)
    {
        int x = i;
        int cnt = 0;
        while(x)
        {
            x/=10;
            cnt++;
        }
        if(cnt&1)
            ans++;
    }
    cout<<ans;
}
