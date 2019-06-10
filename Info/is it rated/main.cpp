#include <iostream>

using namespace std;

int main()
{
    int lasta=0,lastb=0,a,b,n,i,ok=0;
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>a>>b;
        if(a!=b)
        {
            cout<<"rated";
            return 0;
        }
        if(lasta && lastb && lastb==lasta && b>lastb)
        {
            ok=1;
        }
        lasta=a;
        lastb=b;
    }
    if(ok)
        cout<<"unrated";
    else
        cout<<"maybe";
}
