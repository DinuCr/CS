#include <iostream>

using namespace std;

int main()
{
    long long n,a,b,c;
    cin>>n>>a>>b>>c;
    if(n%4==0)
        cout<<0;
    else
    if(n%4==1)
    {
        cout<<min(a*3,min(c,a+b));
    }
    else
    if(n%4==2)
    {
        cout<<min(b,min(2*a,c*2));
    }
    else
    if(n%4==3)
    {
        cout<<min(a,min(3*c,c+b));
    }
}
