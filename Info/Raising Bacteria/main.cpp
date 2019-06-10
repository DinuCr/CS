#include <iostream>

using namespace std;
int a,nr;
int main()
{
    cin>>a;
    while(a)
    {
        while(a%2==0)
        a/=2;
        a--;
        nr++;
    }
    cout<<nr;
}
