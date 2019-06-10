#include <iostream>

using namespace std;
long long s,n,p,x;
int main()
{
    cin>>n;
    s=0;
    p=9;
    x=1;
    while(n>0)
    {
       s+=min(p*x,n*x);
       n-=p;
       p*=10;
       x+=1;
    }
    cout<<s;
}
