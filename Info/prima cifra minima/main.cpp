#include<iostream>
using namespace std;
int main()
{
    int n,x,x2,mn,nr,i;
    cin>>n;
    mn=10;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        x2=x;
        while(x>10)
            x/=10;
        if(x<mn)
        {
            mn=x;
            nr=x2;
        }
        else
        if(x==mn)
        if(x2>nr)
        nr=x2;
    }
    cout<<nr;
    return 0;
}
