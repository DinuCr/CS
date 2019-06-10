#include <iostream>

using namespace std;
int a,b,c,i,j,ok;
int main()
{
    cin>>a>>b>>c;
    ok=0;
    for(i=0;i<=c/a;i++)
    for(j=0;j<=c/b;j++)
    if(i*a+b*j==c)
    {
        ok=1;
        break;
    }
    if(ok)
        cout<<"YES";
    else
        cout<<"NO";

}
