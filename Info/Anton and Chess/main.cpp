#include <iostream>
#include <vector>

using namespace std;

long long x,y;
long long a,b,ok1,ok2,ok3,ok4,ok5,ok6,ok7,ok8,d1,d2,d3,d4,d5,d6,d7,d8,n,i;
char c;

int main()
{
    cin>>n;
    cin>>x>>y;
    for(i=1; i<=n; ++i)
    {
        cin>>c>>a>>b;
        //caz 1
        if(b==y && a>x && (a-x<d1 || d1==0))
        {
            d1=a-x;
            if(c=='B')
                ok1=0;
            else
                ok1=1;
        }
        //caz 2
        if(a-x==b-y && a>x && (a-x<d2 || d2==0))
        {
            d2=a-x;
            if(c=='R')
                ok2=0;
            else
                ok2=1;
        }
        //caz 3
        if(x==a && b>y && (b-y<d3 || d3==0))
        {
            d3=b-y;
            if(c=='B')
                ok3=0;
            else
                ok3=1;
        }
        //caz 4
        if(x-a==b-y && x>a && (x-a<d4 || d4==0))
        {
            d4=x-a;
            if(c=='R')
                ok4=0;
            else
                ok4=1;
        }
        //caz 5
        if(y==b && x>a && (x-a<d5 || d5==0))
        {
            d5=x-a;
            if(c=='B')
                ok5=0;
            else
                ok5=1;
        }
        //caz 6
        if(x-a==y-b && x>a && (x-a<d6 || d6==0))
        {
            d6=x-a;
            if(c=='R')
                ok6=0;
            else
                ok6=1;
        }
        //caz 7
        if(x==a && b<y && (y-b<d7 || d7==0))
        {
            d7=y-b;
            if(c=='B')
                ok7=0;
            else
                ok7=1;
        }
        //caz 8
        if(a-x==y-b && x<a && (a-x<d8 || d8==0))
        {
            d8=a-x;
            if(c=='R')
                ok8=0;
            else
                ok8=1;
        }
    }
    if(ok1 || ok2 || ok3 || ok4 || ok5 || ok6 || ok7 || ok8)
        cout<<"YES";
    else
        cout<<"NO";
}
