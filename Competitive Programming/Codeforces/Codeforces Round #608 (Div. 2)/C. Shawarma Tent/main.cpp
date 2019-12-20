#include <iostream>

using namespace std;

int a,b,c,d,n,sx,sy;

int main()
{
    cin>>n>>sx>>sy;
    for(int i=0; i<n; ++i)
    {
        int x,y;
        cin>>x>>y;
        if(y>sy)
            a++;
        if(x>sx)
            b++;
        if(y<sy)
            c++;
        if(x<sx)
            d++;
    }
    if(a>=b && a>=c && a>=d)
    {
        cout<<a<<'\n';
        cout<<sx<<' '<<sy+1;
    }
    else
    if(b>=a && b>=c && b>=d)
    {
        cout<<b<<'\n';
        cout<<sx+1<<' '<<sy;
    }
    else
    if(c>=a && c>=b && c>=d)
    {
        cout<<c<<'\n';
        cout<<sx<<' '<<sy-1;
    }
    else
    {
        cout<<d<<'\n';
        cout<<sx-1<<' '<<sy;
    }
}
