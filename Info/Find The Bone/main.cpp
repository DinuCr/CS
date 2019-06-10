#include <iostream>

using namespace std;

#define nmax 1000010

int h[nmax];
int b,m,n,k,i,x,y;

int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    b=1;
    for(i=1; i<=m; ++i)
    {
        cin>>x;
        h[x]=1;
    }
    for(i=1; i<=k; ++i)
    {
        cin>>x>>y;
        if(h[b])
        {
            cout<<b;
            return 0;
        }
        if(b==x)
            b=y;
        else
        if(b==y)
            b=x;
    }
    cout<<b;
}
