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

    int a,b;
    cin>>a>>b;
    int curr = 1;
    int ans = 0;
    while(curr<b)
        curr+=a-1,ans++;
    cout<<ans;
}
