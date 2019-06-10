#include <iostream>

using namespace std;

int main()
{
    int a,b,n;
    cin>>n>>a>>b;
    for(int i=0; i<=n; i+=a)
        if((n-i)%b==0)
        {
            cout<<"YES"<<'\n';
            cout<<i/a<<' '<<(n-i)/b;
            return 0;
        }
    cout<<"NO";
}
