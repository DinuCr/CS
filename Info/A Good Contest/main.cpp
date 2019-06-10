#include <iostream>

using namespace std;

char s[100];
int n,i,ok,a,b;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>s>>a>>b;
        if(a<b & a>=2400)
            ok=1;
    }
    if(ok)
        cout<<"YES";
    else
        cout<<"NO";

}
