#include <iostream>
#include<fstream>
using namespace std;
ifstream f("cart.in");
ofstream g("cart.out");
int v[17],x,nr,C,s,n,i,a[17],mx;
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
    f>>n>>mx;
    for(i=1;i<=n;i++)
        f>>v[i];
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
        nr=(mx-x-1)/x+1;
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
    g<<C;
    g.close();
}
