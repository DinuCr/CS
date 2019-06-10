#include <iostream>                                                                                                                   //neacs was here
using namespace std;
unsigned long long a,b;
int main()
{
    cin>>a;
    b=a/10000;
    b=b*10+(a%1000)/100;
    b=b*10+(a%10);
    b=b*10+(a%100)/10;
    b=b*10+(a/1000)%10;
    a=b;
    b=(b*b*b)%100000;
    b=(b*a)%100000;
    b=(b*a)%100000;
    if(b!=0)cout<<b;
    else cout<<"00000";
    return 0;
}
