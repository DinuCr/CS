#include <iostream>

using namespace std;

int main()
{
    int n,i,nr=0;
    cin>>n;
    char a,b;
    for(i=1;i<=n;++i)
    {
        cin>>b;
        if(a!=b)
        {
            nr++;
            a=b;
        }
    }
    cout<<nr;
}
