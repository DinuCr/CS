#include <iostream>

using namespace std;
long long s,s2,n;
int main()
{
    cin>>n;
    n++;
    s2=n*(n-1)/2;
    s2%=666013;
    s2*=s2;
    s2%=666013;
    if(n*(n-1)%6==0)
    {
        s=n*(n-1)/6;
        s%=666013;
        s*=n;
        s%=666013;
        s*=2*n-1;
        s%=666013;
    }
    else
    if(n*(2*n-1)%6==0)
    {
        s=n*(2*n-1)/6;
        s%=666013;
        s*=n-1;
        s%=666013;
        s*=n;
        s%=666013;
    }
    else
    {
        s=(n-1)*(2*n-1)/6;
        s%=666013;
        s*=n;
        s%=666013;
        s*=n;
        s%=666013;
    }
    if(s2>s)
        s+=666013;
    s-=s2;
    s%=666013;
    cout<<s;
}
