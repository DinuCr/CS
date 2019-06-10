#include <iostream>

using namespace std;
int n,i,m,s,nr,x1,x2;
char v[100010],x;
int main()
{
    cin>>n;
    cin>>v[1];
    x=v[1];
    v[1]=0;
    m=1;
    for(i=2;i<=n;i++)
    {
        cin>>v[i];
        if(v[i]!=x)
        {
            x=v[i];
            v[i]=0;
            m++;
        }
    }
    x1=1;
    x2=1;
    nr=0;
    for(i=2;i<=n;i++)
    {
        if(v[i]==v[i-1] && v[i]!=0)
            nr++;
        else
        {
            if(nr>x2-x1)
            {
                x2=i;
                x1=i-nr;
            }
            nr=1;
        }
    }
    if(nr>x2-x1)
            {
                x2=i-1;
                x1=i-nr-1;
            }
    if(x2>x1+1)
        m+=2;
    cout<<m;
}
