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

    int n,i,x,a=0,b=0;

    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        if(x&1)
            a++;
        else
            b++;
    }cout<<min(a,b);
}
