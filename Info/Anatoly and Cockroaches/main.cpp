#include <iostream>

using namespace std;

int n,i,nr,j,mn;
char c;
bool v[100100],b[100100],a[100100];

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>c;
        if(c=='r')
            v[i]=1;
        else
            v[i]=0;
        a[i]=i%2;
        b[i]=(i+1)%2;
    }
    int d0=0,d1=0;
    for(i=1; i<=n; ++i)
    {
        if(v[i]!=a[i])
        {
            if(a[i]==0)
                d0++;
            else
                d1++;
        }
    }
    mn=max(d0,d1);
    d0=0,d1=0;
    for(i=1; i<=n; ++i)
    {
        if(v[i]!=b[i])
        {
            if(b[i]==0)
                d0++;
            else
                d1++;
        }
    }
    mn=min(mn,max(d0,d1));
    cout<<mn;
}
