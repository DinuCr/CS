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

    int n,d,e;

    cin>>n>>d>>e;

    e*=5;

    int ans = min(n%d%e,n%e%d);

    int n2 = n;
    int cnt = 0;

    while(n>=d && cnt<e)
    {
        cnt++;
        n-=d;
        ans=min(ans,n%e);
    }

    n = n2;
    cnt =0;

    while(n>=e && cnt<d)
    {
        cnt++;
        n-=e;
        ans=min(ans,n%d);
    }

    cout<<ans;
}
