#include <iostream>
using namespace std;
int v[30001],i,ok,n,t;
int main()
{
    cin>>n>>t;
    for(i=1;i<n;i++)
        cin>>v[i];
    i=1;
    while(i!=n)
    {
        i=i+v[i];
        if(i==t)
        {
            ok=true;
            break;
        }
    }
    if(ok)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
