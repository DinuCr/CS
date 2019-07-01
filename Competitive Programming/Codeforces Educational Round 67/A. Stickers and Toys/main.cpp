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

    int t,n,b,c;

    cin>>t;

    while(t--)
    {
        cin>>n>>b>>c;
        cout<<max(n-b+1,n-c+1)<<'\n';
    }
}
