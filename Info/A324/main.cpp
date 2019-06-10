#include <iostream>

using namespace std;
int n,i,t;

int main()
{
    cin>>n>>t;
    if(t==10 && n==1)
        cout<<"-1";
    else
    if(t!=10)
        for(i=1;i<=n;i++)
        cout<<t;
    else
    if(t==10)
    {
        for(i=1;i<=n-1;i++)
        cout<<'1';
        cout<<'0';
    }
}
