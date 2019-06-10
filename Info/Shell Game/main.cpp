#include <iostream>

using namespace std;

int i,n,k;

int main()
{
    cin>>n>>k;
    n%=6;
    for(i=n; i>0; --i)
        if(i%2==0)
        {
            if(k==2)
                k=1;
            else
            if(k==1)
                k=2;
        }
        else
        {
            if(k!=2)
            k=1-k;
        }
    cout<<k;
}
