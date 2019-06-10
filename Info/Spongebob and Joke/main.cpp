#include <iostream>

using namespace std;

int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>f[i];
    for(i=1;i<=m;i++)
    {
        cin>>x;
        b[x]++;
    }
    for(i=1;i<=n;i++)
    if(b[f[i]]>0)
    {
        a[i]=f[i];
        b[f[i]]--;
    }
    for(i=1;i<=n;i++)
        s+=b[i];
    if(s<2)
    {
        for(i=1;i<=n;i++)
            if(b[x]>0)
            a[m]=x;
        cout<<"Possible\n";
        for(i=1;i<=m;i++)
            cout<<w[i];
    }
}
