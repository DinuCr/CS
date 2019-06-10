#include <iostream>
using namespace std;
long long s,i,n;
int main()
{
    cin>>n;
    i=1;
    while(s+i<n)
    {
        s+=i;
        i++;
    }
    cout<<n-s;
}
