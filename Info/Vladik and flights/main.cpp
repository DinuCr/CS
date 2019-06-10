#include <iostream>

using namespace std;

char v[100100];

int main()
{
    int a,n,b;
    cin>>n>>a>>b;
    for(int i=1; i<=n; ++i)
        cin>>v[i];
    if(v[a]==v[b])
        cout<<'0';
    else
    cout<<'1';
}
