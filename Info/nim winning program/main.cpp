#include <iostream>

using namespace std;

int main()
{
    int n,i;
    int ok = 1;
    while(ok)
    {
        cin>>n;
        int v[100];
        int curr = 0;
        for(i=1; i<=n; ++i)
        {
            cin>>v[i];
            curr^=v[i];
        }
        cout<<'\n'<<curr<<'\n';
        for(i=1; i<=n; ++i)
            if((v[i]^curr)<=v[i])
            {
                v[i]=v[i]^curr;
                break;
            }
        for(i=1; i<=n; ++i)
            cout<<v[i]<<' ';
        cout<<'\n';
        cin>>ok;
        cout<<'\n';
    }

}
