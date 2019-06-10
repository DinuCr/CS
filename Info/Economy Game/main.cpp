#include <iostream>

using namespace std;

const int a = 1234567;
const int b = 123456;
const int c = 1234;

int i,j,n,ok;

int main()
{
    cin>>n;

    for(i=0; i*a<=n && !ok; ++i)
    {
        for(j=0; i*a+j*b<=n && !ok; ++j)
        {
            if((n-i*a-j*b)%c==0)
                ok=1;
        }
    }
    if(ok)
        cout<<"YES";
    else
        cout<<"NO";
}
