#include <iostream>

using namespace std;

int main()
{
    int i,n,a,b,c,ans;
    a=b=c=0;
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        if(x%3==0)
            ++a;
        else
        if(x%3==1)
            ++b;
        else
        ++c;
    }
    ans= (a-1)*a/2+b*c;
    cout<<ans;
}
