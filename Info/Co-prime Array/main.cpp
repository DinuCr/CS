#include <iostream>

using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
    return gcd(b,a%b);
}
int i,n,v[1100],nr;
int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    for(i=2; i<=n; ++i)
    {
        if(gcd(v[i],v[i-1])!=1)
                nr++;
    }
    cout<<nr<<'\n';
    cout<<v[1]<<' ';
    for(i=2; i<=n; ++i)
    {
        if(gcd(v[i],v[i-1])!=1)
                cout<<"1 ",nr++;
        cout<<v[i]<<' ';
    }
}
