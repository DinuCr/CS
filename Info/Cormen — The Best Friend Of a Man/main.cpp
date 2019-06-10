#include <iostream>

using namespace std;

int n,i,k,nr,v[1000];

int main()
{
    cin>>n>>k;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    for(i=2; i<=n; ++i)
        if(v[i-1]+v[i]<k)
        {
            nr+=k-v[i-1]-v[i];
            v[i]+=k-v[i-1]-v[i];
        }
    cout<<nr<<'\n';
    for(i=1; i<=n; ++i)
        cout<<v[i]<<' ';

}
