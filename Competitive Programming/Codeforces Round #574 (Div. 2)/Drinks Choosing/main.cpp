#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int x,i,n,v[10001],k;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n>>k;
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        v[x]++;
    }
    int ans = 0;
    int ok = 0;
    for(i=1; i<=k; ++i)
    {
        int x = v[i]%2;
        ans+=v[i]-x;
        if(x && ok==0)
            ok=1,ans++;
        else
        if(x)
            ok=0;
    }
    cout<<ans;

}
