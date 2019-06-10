#include <iostream>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    cout<<(k-1)/(m*2)+1<<' '<<(k-1)%(m*2)/2+1<<' ';
    if(k%(m*2)%2==1)
        cout<<'L';
    else
        cout<<'R';
}
