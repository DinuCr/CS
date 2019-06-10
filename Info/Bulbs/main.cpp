#include <iostream>

using namespace std;
int v[110],n,m,i,j,x,y,ok;
int main()
{
    cin>>m>>n;
    for(i=1;i<=m;i++)
    {
        cin>>x;
        for(j=1;j<=x;j++)
            cin>>y,v[y]=1;
    }
    ok=1;
    for(i=1;i<=n;i++)
        if(v[i]==0)
        ok=0;
    if(ok)
        cout<<"YES";
    else
        cout<<"NO";
}
