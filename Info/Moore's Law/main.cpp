#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double a,x=1.000000011;
int b;
double p(double x,int n)
{
    if(n==0)
        return 1;
    else
    if(n==1)
        return x;
    else
    {
        if(n%2==0)
            return p(x*x,n/2);
        else
            return x*p(x,n-1);
    }
}
int main()
{
    cin>>a>>b;
    cout<<setprecision(7)<<fixed<<a*pow(x,b);
}
