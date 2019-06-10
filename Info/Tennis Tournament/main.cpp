#include <iostream>
#include <cmath>
using namespace std;
int n,b,p,n2,x,y;
int main()
{
    cin>>n>>b>>p;
    y=n*p;
    while(n>1)
    {
        n2=log2(n);
        x+=(1<<n2)*b+(1<<n2)/2;
        n-=(1<<n2)/2;
    }
    cout<<x<<' '<<y;
}
