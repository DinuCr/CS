#include <iostream>

using namespace std;

int n;
int i,ans;
int v[210100];

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        char c;
        cin>>c;
        if(c=='<')
            v[i]=-1;
        else
            v[i]=1;
    }
    for(i=1; v[i]==-1; ++i)
        ++ans;
    for(i=n; v[i]==1; --i)
        ++ans;
    cout<<ans;
}
