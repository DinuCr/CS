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

    int b,g,n;

    cin>>b>>g>>n;

    int l,r;

    if(b>=n)
        r=n;
    else
        r=b;

    if(g>=n)
        l=0;
    else
        l=n-g;
    cout<<r-l+1;
}
