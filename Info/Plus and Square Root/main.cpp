#include <iostream>

using namespace std;

long long n,i;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        if(i==1)
            cout<<2<<'\n';
        else
            cout<<i*(i+1)*(i+1)-i+1<<'\n';
    }
}
