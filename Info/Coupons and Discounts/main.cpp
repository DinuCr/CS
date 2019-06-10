#include <iostream>

using namespace std;

int n,i,v[200100],ok;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    for(i=1; i<=n; ++i)
    {
        if(v[i]%2==1)
        {
            --v[i];
            --v[i+1];
            v[i]=0;
        }
        else
        if(v[i]>0)
            v[i]=0;
    }
    for(i=1; i<=n+1; ++i)
        if(v[i]!=0)
        {
            cout<<"NO";
            return 0;
        }
    cout<<"YES";
}
