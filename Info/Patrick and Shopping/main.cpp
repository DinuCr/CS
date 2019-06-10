#include <iostream>
using namespace std;
int a,b,c,mn;
int main()
{
    cin>>a>>b>>c;
    mn=min(2*a+2*b,a+b+c);
    mn=min(mn,min(2*b+2*c,2*a+2*c));
    cout<<mn;
}
