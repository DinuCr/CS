#include <iostream>
using namespace std;
int a,b,n,i;
int gcd(int a,int b)
{
    int r;
    r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    cin>>a>>b>>n;
    while(n)
    {
        if(!i)
        n-=gcd(n,a);
        else
        n-=gcd(n,b);
        i=!i;
    }
    cout<<!i;
}
