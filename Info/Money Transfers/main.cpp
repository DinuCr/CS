#include <iostream>
#include <map>

using namespace std;

map <long long,int> d;

int n,v[100100],i,mn;

int main()
{
    cin>>n;

    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
    }

    long long s = 0;

    mn=n-1;

    for(i=1; i<=n; ++i)
    {
        s+=v[i];
        ++d[s];
        mn=min(mn,n-d[s]);
    }
    cout<<mn;
}
