#include <iostream>
using namespace std;
int v[100010];
int n,i,j,h,d,h2,x,y,z;
int main()
{
    cin>>n>>d>>h;
    int ok=(d==h);
    if(n==2)
        cout<<"1 2";
    else
    if((2*h<d || d==1) && n>2)
        cout<<"-1";
    else
    {
        h2=h-1;
        cout<<"1 2\n";
        x++;
        while(h2)
        {
            x++;
            v[x]=x+1;
            h2--;
        }
        y=1;
        d-=h;
        x++;
        while(d)
        {
            v[y]=x+1;
            y=x+1;
            x++;
            d--;
        }
        for(i=1;i<=n;i++)
        if(v[i]!=0)
        cout<<i<<' '<<v[i]<<'\n';
        if(ok)
            z=2;
        else
            z=1;
        while(x<n)
        {
            cout<<z<<' '<<x+1<<'\n';
            x++;
        }
    }
}
