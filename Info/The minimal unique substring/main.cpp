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

    int n,k,a,i;
    cin>>n>>k;
    a = (n-k)>>1;
    for(i=1; i<=n; ++i)
        if((i-1)%(a+1)<a)
            cout<<0;
        else
            cout<<1;
}
