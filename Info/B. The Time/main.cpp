#include <iostream>

using namespace std;
long long x,a,b;
char c;
int main()
{
    cin>>a>>c>>b;
    cin>>x;
    b+=x;
    a+=b/60;
    a=a%24;
    b=b%60;
    if(a==0)
        cout<<"00";
    else
    if(a<=9)
        cout<<'0'<<a;
    else
    cout<<a;
    cout<<c;
    if(b==0)
        cout<<"00";
    else
    if(b<=9)
        cout<<'0'<<b;
    else
    cout<<b;

}
