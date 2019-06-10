#include <iostream>

using namespace std;
int a,b,c;
int main()
{
    cin>>a>>b>>c;
    if((c<0 && b>a) || (c>0 && a>b))
        cout<<"NO";
    else
    {
        if((c!=0 && (b-a)%c==0) || (b-a==c))
            cout<<"YES";
        else
            cout<<"NO";
    }
}

