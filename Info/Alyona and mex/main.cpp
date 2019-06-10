#include <iostream>

using namespace std;

int n,m,i,a,b,ans=10000000;

int main()
{
    cin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        cin>>a>>b;
        ans=min(ans,b-a+1);
    }
    cout<<ans<<'\n';
    for(i=1; i<=n; ++i)
        cout<<i%ans<<' ';
}
