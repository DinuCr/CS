#include<iostream>
using namespace std;
int main()
{
    int n,m,p,z;
    cin>>n>>m;
    cout<<'{';
    for(p=1;p<=n;p++)
        for(z=1;z<=m;z++)
    {
        cout<<"("<<p<<","<<z<<")";
        if(p<n||z<m)
            cout<<",";
    }
    cout<<"}";
    return 0;
}
