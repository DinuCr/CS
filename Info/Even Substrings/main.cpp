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

    string s;
    int n;
    cin>>n>>s;
    ll ans = 0;
    for(int i=0; i<n; ++i)
        if((s[i]-'0')%2==0)
            ans+=i+1;
    cout<<ans;
}
