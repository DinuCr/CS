#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ll q,v[4];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>q;

    while(q--)
    {
        cin>>v[1]>>v[2]>>v[3];
        sort(v+1,v+4);
        ll a = v[1];
        ll b = v[2];
        v[3] -= b-a;
        a = b;
        cout<<a+v[3]/2<<'\n';
    }
}
