#include <iostream>

using namespace std;

int n,m,i,j,v[51][51];

int main()
{
    cin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            cin>>v[i][j];
    for(i=1; i<=n; ++i)
    {
        if(!v[i][1])
            for(j=1; j<=m; ++j)
                v[i][j]=!v[i][j];
    }
    for(j=2; j<=m; ++j)
    {
        int curr = 0 ;
        for(i=1; i<=n; ++i)
            curr+=v[i][j];
        if(curr<=n/2)
            for(i=1; i<=n; ++i)
                v[i][j]=!v[i][j];
    }
    long long ans = 0;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            ans+=(1LL*v[i][j])<<(m-j);
    cout<<ans;
}
