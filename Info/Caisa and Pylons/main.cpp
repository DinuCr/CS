#include <iostream>

using namespace std;

int v[100100],i,s,ans,n;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    for(i=1; i<=n; ++i)
    {
        s=s+v[i-1]-v[i];
        if(s<0)
        {   ans+=-s;
            s=0;
        }
    }
    cout<<ans;
}
