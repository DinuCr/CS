#include <iostream>

using namespace std;

int n,c,i,nr,v[100100];

int main()
{
    cin>>n>>c;
    nr=0;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        if(v[i]-v[i-1]>c)
            nr=1;
        else
            ++nr;
    }
    cout<<nr;
}
