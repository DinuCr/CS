#include <iostream>
using namespace std;
int n;
int main()
{
    cin>>n;
    if((n-2)%2==0 && n>2)
        cout<<"YES";
    else
        cout<<"NO";
}
