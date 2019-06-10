#include <iostream>

using namespace std;

int n,v[100],i;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    if(v[n]==0)
            cout<<"UP";
        else
    if(v[n]==15)
            cout<<"DOWN";
    else
    if(n==1)
            cout<<-1;
    else
    if(v[n-1]>v[n])
        cout<<"DOWN";
    else
        cout<<"UP";
}
