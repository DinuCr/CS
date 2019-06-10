#include <iostream>
#include <algorithm>

using namespace std;

int v[10100];
int n,i,cnt;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        if(v[i]==i)
        {
            ++cnt;
            v[i]=0;
        }
    }
    sort(v+1,v+n+1);
    int sum = 0;
    for(i=1; i<=n; ++i)
        if(v[i]!=v[i-1])
        ++sum;
    cout<<sum/2+cnt;
}
