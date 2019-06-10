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

    int n,ans=0,i;

    cin>>n;

    for(i=1; i<=n; ++i)
    {
        char x;
        cin>>x;
        if(x=='+')
            ans++;
        else
            ans--;
        if(ans<0)
            ans=0;
    }
    cout<<max(ans,0);
}
