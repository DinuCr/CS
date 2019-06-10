#include <iostream>

using namespace std;
int n;
int main()
{
    cin>>n;
    if(n%2==1)
        cout<<'0';
    else
    {
        if(n%4==0)
            cout<<n/4-1;
        else
            cout<<n/4;
    }
}
