#include<iostream>
#include<cstring>
using namespace std;
char s[1000],x;
int main()
{
    cin>>x;
    if(x>'Z')
        x-=32;
    cin>>s;
    cout<<x<<s;
}
