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
    int n,v;
    cin>>n>>v;
    int curr = 0;
    int ans = 0;
    for(int i=1; i<=n; ++i)
    {
        if(n-i>curr)
        {
            ans += i*(min(v,n-i)-curr);
            curr = min(v,n-i);
        }
        curr--;
    }
    cout<<ans;
}
