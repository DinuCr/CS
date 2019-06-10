#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define nmax (int)1e5+10

int n,i,m,a[nmax],b[nmax];

int main()
{
    cin>>i>>n>>m;
    for(i=1; i<=n; ++i)
        cin>>a[i];
    for(i=1; i<=m; ++i)
        cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    long long ans = 0;
    int l = 1;
    for(i=1; i<=n; ++i)
    {
        while(a[i]>b[l+1] && l<m)
            ++l;
        if(l<m)
            ans += min(abs(a[i]-b[l]),abs(b[l+1]-a[i]));
        else
            ans += abs(a[i]-b[l]);
    }
    cout<<ans;
}
