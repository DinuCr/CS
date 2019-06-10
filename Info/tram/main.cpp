#include<iostream>
using namespace std;
int n,i,a,b,mx,s;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        s=s-a+b;
        mx=max(mx,s);
    }
    cout<<mx;
}
