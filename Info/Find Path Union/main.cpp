#include <iostream>
#include <tr1\unordered_set>
#include <algorithm>

using namespace std;
using namespace tr1;

#define nmax (int)5e5+10
#define ll long long

ll curr[nmax];
tr1::unordered_set <ll> v[65];
int n,i,x;

int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>curr[i];
    }
    sort(curr,curr+n);
    x = 1;
    for(i=0; i<n; ++i)
    {
        ll c = 1LL<<x;
        while(i<n && curr[i]<c)
            v[x].insert(curr[i]),++i;
        --i,++x;
    }
    ll ans = 0;
    tr1::unordered_set<ll> :: iterator a;
    for(i=x-1; i>1; --i)
    {
        ll last = -1;
        ll b = 1;
        while(v[i].size())
        {
            a = (v[i].begin());
            if(b++<3)
            {
                if(last!=(*(a)))
                    v[i-1].insert((*(a))>>1),
                    ++ans;
            }
            else
            {
                b=0;
                if(last!=(*(a)))
                {
                    ++ans;
                    if(v[i-1].find((*(a))>>1)==v[i-1].end())
                        v[i-1].insert((*(a))>>1);
                }
            }
            last = (*(a));
            v[i].erase(a);
        }
    }
    cout<<ans;
}
