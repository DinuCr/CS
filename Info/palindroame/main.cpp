#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n,i;

    cin>>n;
    ll ans = 0;
    for(i=1; i<=n; ++i)
    {
        int x,curr=0,x2;
        cin>>x;
        x2=x;
        if(x%10==0)
            continue;
        if(x<10)
            ans+=x;
        else
        while(x && x>curr)
        {
            curr=curr*10+x%10;
            x/=10;
            if(x==curr || x/10==curr)
            {
                ans+=x2;
                break;
            }
        }
    }
    cout<<ans;
}
