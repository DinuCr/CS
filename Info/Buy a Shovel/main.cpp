#include <iostream>

using namespace std;

int main()
{
    int n,k,i;
    cin>>n>>k;
    for(i=1; i<=10; ++i)
    {
        if(n*i%10==k || n*i%10==0)
        {
            cout<<i;
            return 0;
        }
    }
}
