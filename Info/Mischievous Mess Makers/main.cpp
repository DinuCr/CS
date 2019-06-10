#include <iostream>

using namespace std;
long long n,s,i,k;
int main()
{
    cin>>n>>k;
    for(i=1;i<=n/2 && k>0;i++,k--)
    {
        s+=n-2*i+1+n-2*i;
    }
    cout<<s;
}
