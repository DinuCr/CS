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

    int n,x,last=0,cnt=1,ans=0,i;
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        if(x<=last)
            cnt++,last=x;
        else
            cnt=1,last=x;
        ans=max(ans,cnt);
    }
    cout<<ans-1;
}
