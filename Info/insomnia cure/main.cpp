#include <iostream>
using namespace std;
int a[5],v[5],s,nr,mx,n,i,x,C;
int cmmmc(int a,int b)
{
    int r,z;
    r=a%b;z=a*b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return z/b;
}
int main()
{
    cin>>v[1]>>v[2]>>v[3]>>v[4]>>mx;
    n=4;
    a[n]=1;
     while(!a[0])
    {
        s=0;
        for(i=1;i<=n;i++)
            s+=a[i];
        x=1;
        for(i=1;i<=n;i++)
            if(a[i])
                x=cmmmc(x,v[i]);
        nr=mx/x;
        if(s%2==0)
            C-=nr;
        else
            C+=nr;
        i=n;
        while(a[i]==1)
        {
            a[i]=0;
            i--;
        }
        a[i]=1;
    }
    cout<<C;
}
