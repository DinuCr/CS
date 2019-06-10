#include <iostream>

using namespace std;

long long a,b,c,d,ans;

int main()
{
    cin>>a>>b>>c>>d;
    while(a>0 && c>0 && d>0)
    {
        --a;
        --c;
        --d;
        ans+=256;
    }
    while(a>0 && b>0)
    {
        --a;
        --b;
        ans+=32;
    }
    cout<<ans;
}
