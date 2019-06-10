#include <iostream>
#include <cmath>

using namespace std;

bool prime(int x)
{
    int a = sqrt(x);
    for(int i=2; i<=a; ++i)
        if(x%i==0)
            return 0;
    return 1;
}

int main()
{
    int n,m;
    cin>>n;
    for(m=1; m<=1000; ++m)
        if(!prime(m*n+1))
        {
            cout<<m;
            return 0;
        }
}
