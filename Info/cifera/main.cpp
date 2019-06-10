#include<iostream>
using namespace std;
int x,l,k;
int main()
{
    cin>>k>>l;
    if(l<k)
        cout<<"NO";
    else
    if(l==k)
        cout<<"YES\n0";
    else
    {
        while(l%k==0)
        {
            l/=k;
            x++;
        }
        x--;
        if(l==1)
            cout<<"YES\n"<<x;
        else
            cout<<"NO";
    }
}
