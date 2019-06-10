#include <iostream>

using namespace std;
int n,i,x,x2,mx,nr;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x<x2)
        {
            nr=1;
        }
        else
        nr++;
        x2=x;
        mx=max(nr,mx);
    }
    cout<<mx;
}
