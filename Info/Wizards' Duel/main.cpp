#include <iostream>
using namespace std;
float s,l,v1,x,v2,t;
int main()
{
    cin>>l>>v1>>v2;
    t=(float)(2*l)/(v1+v2);
    x=t*v1/2;
    if(x>l)
        x-=l;
    cout<<x;
}
