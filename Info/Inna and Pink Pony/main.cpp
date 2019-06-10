#include <iostream>

using namespace std;

int n,m,a,b,i,j,x1,x2,y1,y2,mn;


int main()
{
    cin>>n>>m>>i>>j>>a>>b;
    x1=i-1;
    x2=n-i;
    y1=j-1;
    y2=m-j;
    mn=10000000;
    if((x1%a!=0 && x2%a!=0) || (y1%b!=0 && y2%b!=0))
    {
        cout<<"Poor Inna and pony!";
        return 0;
    }
    if( (x1%a==0 && y1%b==0 && x1/a%2!=y1/b%2) && (x2%a==0 && y1%b==0 && x2/a%2!=y1/b%2) && (x1%a==0 && y2%b==0 && x1/a%2!=y2/b%2) && (x2%a==0 && y2%b==0 && x2/a%2!=y2/b%2) )
    {

        cout<<"Poor Inna and pony!";
        return 0;
    }
    if(a+i>n && i-a<=0)
    {
        cout<<"Poor Inna and pony!";
        return 0;
    }
    if(b+j>m && j-b<=0)
    {
        cout<<"Poor Inna and pony!";
        return 0;
    }


    if(x1%a==0 && y1%b==0 && x1/a%2==y1/b%2)
    {
        mn=min(mn,max(x1/a,y1/b));
    }

    if(x2%a==0 && y1%b==0 && x2/a%2==y1/b%2)
    {
        mn=min(mn,max(x2/a,y1/b));
    }

    if(x1%a==0 && y2%b==0 && x1/a%2==y2/b%2)
    {
        mn=min(mn,max(x1/a,y2/b));
    }

    if(x2%a==0 && y2%b==0 && x2/a%2==y2/b%2)
    {
        mn=min(mn,max(x2/a,y2/b));
    }
    cout<<mn;

}
