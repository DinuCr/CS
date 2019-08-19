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

    ll t,n,k;

    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(n/k%k==0)
            cout<<"NO\n";
        else cout<<"YES\n";
    }
}
