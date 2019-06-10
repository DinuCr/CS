#include <iostream>
#include <fstream>
using namespace std;
int a,b,d,x,y,n,i,c;
void gdc(int a,int b,int &d,int &x,int &y)
{
    int c;
    if(b==0)
    {
        x=1;
        y=0;
        d=a;
    }
    else
    {
        int x0,y0;
        gdc(b,a%b,d,x0,y0);
        x=y0;
        y=x0-a/b*y0;
    }
}
int main()
{
    ifstream f("euclid3.in");
    ofstream g("euclid3.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b>>c;
        gdc(a,b,d,x,y);
        if(c%d!=0)
            g<<"0 0\n";
        else
            g<<x*(c/d)<<' '<<y*(c/d)<<'\n';
    }
}
