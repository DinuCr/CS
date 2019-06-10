#include <iostream>

using namespace std;
int nr,n,k,i,x;
int main()
{
    cin>>n>>k;
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        if(x<=k)
            ++nr;
        else
            nr+=2;
    }
    cout<<nr;
}
