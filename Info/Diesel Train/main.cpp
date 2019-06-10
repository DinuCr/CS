#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

vector <int> v;
int n,l,d;

int main()
{
    cin>>d>>l>>n;
    for(int i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    v.push_back(d);
    sort(v.begin(),v.end());
    long double ans = 0;
    int last = 0;
    for(auto it:v)
    {
        if(last+l<it)
            ans += (long double)(it-last-l)/4*(it-last-l);
        last = it;
    }
    cout<<fixed<<setprecision(10)<<(long double)ans/d;
}
