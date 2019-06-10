#include <iostream>

using namespace std;
int v[200][200],i,j,mn,mx,n,m;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    cin>>v[i][j];
    for(i=1;i<=n;i++)
    {
        mn=v[i][1];
        for(j=2;j<=m;j++)
            mn=min(mn,v[i][j]);
        mx=max(mx,mn);
    }
    cout<<mx;
}
