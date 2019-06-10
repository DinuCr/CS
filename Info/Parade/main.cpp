#include <iostream>
#include <cmath>
using namespace std;

int v[100100],w[100100];
int l,r,mx,k,i,n;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i]>>w[i];
        l+=v[i];
        r+=w[i];
    }
    int mx=abs(l-r);
    k=0;
    for(i=1; i<=n; ++i)
    {
        if(abs(l-v[i]+w[i]-r+w[i]-v[i])>mx)
        {
            mx=abs(l-v[i]+w[i]-r+w[i]-v[i]);
            k=i;
        }
    }
    cout<<k;
}
