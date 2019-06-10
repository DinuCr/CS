#include <iostream>
using namespace std;
int x,v[1001],i,mx,n,nr;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        v[x]++;
        mx=max(mx,v[x]);
    }
    for(i=1;i<=1000;i++)
        if(v[i])
        nr++;
    cout<<mx<<' '<<nr;
    return 0;
}
