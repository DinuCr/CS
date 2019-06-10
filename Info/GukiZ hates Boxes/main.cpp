#include<iostream>
using namespace std;
int n,m,s,x,i;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        s+=(x+m-1)/m;
    }
    s+=n;
    cout<<s;
}
