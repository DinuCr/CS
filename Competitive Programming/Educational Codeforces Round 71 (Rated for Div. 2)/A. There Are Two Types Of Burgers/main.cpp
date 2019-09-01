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

    int t,a,b,c,d,e;

    cin>>t;

    while(t--)
    {
        cin>>a>>b>>c>>d>>e;
        if(d<e)
            swap(d,e),swap(b,c);
        cout<<min(a/2,b)*d+max(0,min((a-min(a/2,b)*2)/2,c)*e)<<'\n';
    }
}
