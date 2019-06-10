#include <iostream>

using namespace std;
int a,b,i;
int main()
{
    int n;
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        char c;
        cin>>c;
        if(c=='A')
            ++a;
        else
            ++b;
    }
    if(a>b)
        cout<<"Anton";
    if(a<b)
        cout<<"Danik";
    if(b==a)
        cout<<"Friendship";
}
