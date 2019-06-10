#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int time = 4*60 - k;
    int i = 1;
    while(time - i*5 >=0)
    {
        time -= (i++)*5;
    }
    cout<<min(i-1,n);
}
