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

    int t;
    cin>>t;

    while(t--)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int nr = 0;
        nr += a/c + (a%c!=0);
        nr += b/d + (b%d!=0);
        if(nr>k)
            cout<<"-1\n";
        else
            cout<<a/c + (a%c!=0)<<' '<<b/d + (b%d!=0)<<'\n';
    }
}
