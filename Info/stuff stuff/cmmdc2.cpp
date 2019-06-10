#include<iostream>
using namespace std;
int a,b;
int cmmdc(int a,int b)
{
    if(a%b==0)
        return b;
    else
    {
        if(a%2==0 && b%2==0)
            return 2*cmmdc(a/2,b/2);
        else
        if(b%2==0)
            return cmmdc(a,b/2);
        else
            return cmmdc(b,a%b);
    }
}
int main()
{
    cin>>a>>b;
    cout<<cmmdc(a,b);
    return 0;
}
