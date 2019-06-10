#include <iostream>
using namespace std;
int a,n,i,x;
inline bool apr(int a,int b)
{
    while(a!=0)
    {
        if(a%10==b%10)
            b/=10;
        a/=10;
    }
    if(b==0)
        return 1;
    return 0;
}
int main()
{
    cin>>n>>x;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        if(apr(a,x))
            cout<<a<<'\n';
    }
}
