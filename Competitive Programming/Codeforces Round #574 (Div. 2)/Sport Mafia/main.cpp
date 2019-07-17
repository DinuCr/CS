#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int n,k;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n>>k;
    int sum = 0;
    int cnt = 0;
    int ans = 0;
    int i = 0;
    while(cnt < n)
    {
        cnt++;
        if(sum<k)
            sum+=++i;
        else
            sum-=1,ans++;
    }
    cout<<ans;
}
