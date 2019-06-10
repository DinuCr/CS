#include <iostream>

using namespace std;
int v[510][510],i,n,j,m,p,k;
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
    for(j=1;j<k;j++)
    v[i][j]=++p;
    for(i=1;i<=n;i++)
    for(j=k;j<=n;j++)
    v[i][j]=++p;
    int s=0;
    for(i=1;i<=n;i++)
        s+=v[i][k];
    cout<<s<<'\n';
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<v[i][j]<<' ';
        cout<<'\n';
    }
}
