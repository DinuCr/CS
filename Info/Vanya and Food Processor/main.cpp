#include <iostream>
#include <deque>
using namespace std;

deque <int> v;
long long n,k,h,i,s,k2,nr,l,r,x;

int main()
{
    cin>>n>>h>>k;
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        if(x+s<=h)
            s+=x;
        else
            s=x,nr++;
        nr+=s/k;
        s%=k;
    }
    nr+=s/k;
    s%=k;
    if(s)
        nr++;
    cout<<nr;
}
