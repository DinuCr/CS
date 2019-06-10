#include<iostream>
#include<fstream>
using namespace std;
ifstream f("subsir.in");
int v[1001],mx,l[1001],i,j,p,n;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>v[i];
    l[n]=1;
    i=n-1;
    while(i>0)
    {
        mx=1;
        for(j=i+1;j<=n;j++)
            if(v[i]<=v[j])
            mx=max(l[j]+1,mx);
        l[i]=mx;
        i--;
    }
    for(i=1;i<=n;i++)
        if(l[i]>=mx)
        {
            mx=l[i];
            p=i;
        }
    cout<<v[p]<<' ';
    mx--;
    for(i=p+1;i<=n;i++)
        if(l[i]==mx)
    {
        cout<<v[i]<<' ';
        mx--;
    }
    f.close();
    return 0;
}
