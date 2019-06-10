#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int k1,k2,t1,t2;
    cin>>t1>>k1>>t2>>k2;
    double ans = (double)1/((double)k1/t1+(double)k2/t2);
    cout<<setprecision(10)<<fixed<<ans;
}
