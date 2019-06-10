#include <iostream>
#include <cmath>
using namespace std;
int a,b,x,y,z,mnx,mny;
inline int gcd(int a,int b)
{
    while(a!=0)
    {
        int x=a;
        a=b%a;
        b=x;
    }
    return b;
}
int d(int x)
{
    int de=4*a*a*x*x*b*b-4*b*b*(a*a*x*x-z*z);
    if(de<0)
            return 0;
    if(pow(sqrt(de),2)!=de)
        return 0;
    return 1;
}
void s1(int x)
{
    int de=4*a*a*x*x*b*b-4*b*b*(a*a*x*x-z*z);
    de=sqrt(de);
    int num=2*b*b,nr=2*a*x*b+de;
    if(nr%num==0)
        mnx=min(mnx,(int)abs(x)),mny=min(mny,(int)abs(nr/num)/1);
}
void s2(int x)
{
    int de=4*a*a*x*x*b*b-4*b*b*(a*a*x*x-z*z);
    de=sqrt(de);
    int num=2*b*b,nr=2*a*x*b-de;
    if(nr%num==0)
        mnx=min(mnx,(int)abs(x)/1),mny=min(mny,(int)abs(nr/num)/1);
}
int main()
{
    cin>>a>>b;
    z=gcd(a,b);
    int p=a*b;
    mnx=a*a*b*b,mny=a*a*b*b;
    for(x=-p;x<=p;x++)
    {
        if(d(x))
        {
            s1(x);
            s2(x);
        }
        else
        if(d(x)==0)
        s1(x);
    }
    cout<<mnx<<' '<<mny;
}
