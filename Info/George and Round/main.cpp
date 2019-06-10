#include <iostream>

using namespace std;

#define nmax 3100

int v[nmax],w[nmax],i,j,n,m;

int main()
{
    cin>>n>>m;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    for(i=1; i<=m; ++i)
        cin>>w[i];
    i=1;
    j=1;
    while(i<=n && j<=m)
    {
        if(v[i]<=w[j])
            ++i,++j;
        else
            ++j;
    }
    cout<<n-i+1;
}
