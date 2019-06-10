#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[3000000];
int n,i;

int possible(int k)
{
    for(int i=1; i<=n; ++i)
        if(v[i]>=(i-1)*k && v[i]>=(n-i)*k)
            continue;
        else
            return 0;
    return 1;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
    }

    for(i=1; i<=1e9; i<<=2);
    int ans = 0;
    for( ; i; i>>=1)
        if(possible(ans+i))
            ans+=i;
    cout<<ans;
}
