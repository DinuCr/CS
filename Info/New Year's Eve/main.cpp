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

    ll n,k;

    cin>>n>>k;

    ll i;
    if(k==1)
    {
        cout<<n;
        return 0;
    }
    i=1;
    while(i<n)
        i = i*2+1;
    cout<<i;
}
