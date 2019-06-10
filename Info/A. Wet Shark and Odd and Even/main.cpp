#include <iostream>

using namespace std;
long long i,n,mn,s,x;
int main()
{
    mn=100000000000000;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        s+=x;
        if(x%2==1)
            mn=min(mn,x);
    }
    if(s%2==0)
        cout<<s;
    else
        cout<<s-mn;
}
