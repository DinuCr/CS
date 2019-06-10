#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int d=(a+b+c)/3;
    cout<<max(a,max(b,c))-min(a,min(b,c));

}
