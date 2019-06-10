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

    int i,n,x,last1,last0;

    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        if(x)
            last1=i;
        else
            last0=i;
    }
    cout<<min(last1,last0);
}
