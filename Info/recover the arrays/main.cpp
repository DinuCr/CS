#include <iostream>

using namespace std;

int main()
{
    int n,i,v[(int)1e5+10];
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    int cnt = 0;
    for(i=1; i<=n; ++i)
        i+=v[i],++cnt;
    cout<<cnt;
}
