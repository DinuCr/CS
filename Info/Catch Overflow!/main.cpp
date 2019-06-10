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

    int n,i;

    cin>>n;

    vector <pair<ll,ll> > v;

    v.pb(mp(1,0));

    for(i=1; i<=n; ++i)
    {
        string s;
        cin>>s;
        switch(s[0])
        {
        case 'f':
            ll x;
            cin>>x;
            v.pb(mp(x,0));
            break;
        case 'a':
            v[v.size()-1].s++;
            break;
        default:
            v[v.size()-2].s+=v[v.size()-1].f*v[v.size()-1].s;
            v.pop_back();
            break;
        }
        if(v[v.size()-1].f*v[v.size()-1].s>4294967295)
        {
            cout<<"OVERFLOW!!!";
            return 0;
        }
    }
    cout<<v[v.size()-1].f*v[v.size()-1].s;
}
