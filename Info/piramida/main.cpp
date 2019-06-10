#include<iostream>
using namespace std;
int main()
{
    int n,p,x;
    cin>>n;
    for(p=1;p<=n;p++)
    {
        for(x=1;x<=p;x++)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
