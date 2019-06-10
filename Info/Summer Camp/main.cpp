#include <iostream>

using namespace std;

inline int cifre(int n)
{
    if(n>0)
        return 1+cifre(n/10);
    return 0;
}

int i,n,s;

int main()
{
    cin>>n;
    for(i=1; s<n; ++i)
        s+=cifre(i);
    i--;
    n=s-n;
    while(n)
    {
        n--;
        i/=10;
    }
    cout<<i%10;
}
