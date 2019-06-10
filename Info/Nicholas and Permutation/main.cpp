#include <iostream>

using namespace std;

int i,n,x,l,r,mx;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        if(x==1)
            l=i;
        else
        if(x==n)
            r=i;
    }
    mx=max(r-1,n-r);
    mx=max(mx,l-1);
    mx=max(mx,n-l);
    cout<<mx;
}
