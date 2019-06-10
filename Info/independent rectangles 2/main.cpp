#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define mp make_pair
#define f first
#define s second

vector <pair<int,int> > v;

int main()
{
    int ans = 0,i,n;
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        int x,y;
        cin>>x>>y;
        v.push_back(mp(x,y));
    }
    sort(v.begin(),v.end());
    int lasty = 0;
    int curr = 0;
    for(i=v.size()-1; i>=0; --i)
    {
        if(i+1<n && v[i].f!=v[i+1].f)
            lasty=max(lasty,curr),curr=0;
        if(v[i].s>=lasty)
            ++ans,curr=max(curr,v[i].s);
    }
    cout<<ans;
}
