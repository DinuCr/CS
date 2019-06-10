#include <iostream>
using namespace std;
int n,v[10],i,mx,x;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        v[x]++;
        mx=max(mx,v[x]);
    }
    for(i=0;i<=9;i++)
    if(mx==v[i])
    cout<<i<<' ';
}
