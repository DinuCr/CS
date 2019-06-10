#include <iostream>
using namespace std;
int v[100100],nr,mx,i,n,d[100100];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    for(i=1;i<=n;i++)
    {
        d[v[i]]=d[v[i]-1]+1;
        mx=max(mx,d[v[i]]);
    }
    cout<<n-mx;
}
