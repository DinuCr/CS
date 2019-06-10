#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[1000000],b[1000000],h,w,n,m,i,last;
vector <int> ver,orz;

int main()
{
    cin>>h>>w>>n>>m;
    for(i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        orz.push_back(x);
    }
    for(i=1; i<=m; ++i)
    {
        int x;
        cin>>x;
        ver.push_back(x);
    }
    orz.push_back(h);
    ver.push_back(w);
    sort(orz.begin(),orz.end());
    sort(ver.begin(),ver.end());

    last = 0;
    for(auto it:orz)
    {
        a[it-last]++;
        last = it;
    }
    last = 0;
    for(auto it:ver)
    {
        b[it-last]++;
        last = it;
    }
    long long ans = 0 ;
    for(i=1; i<=max(h,w); ++i)
        ans+=(la[i]*b[i];
    cout<<ans;

}
