#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

long long a,n;

void gcd(long long a,long long b,long long &x,long long &y)
{
    if(!b)
    {
        x=1;
        y=0;
    }
    else
    {
        long long x0,y0;
        gcd(b,a%b,x0,y0);
        x=y0;
        y=x0-(a/b)*y0;
    }
}

int main()
{
    fin>>a>>n;
    long long x,y;
    gcd(a,n,x,y);
    if(x<0)
        x+=n;
    x%=n;
    fout<<x;
}
