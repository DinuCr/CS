#include <iostream>
#include <fstream>
using namespace std;
ifstream f("flori4.in");
ofstream g("flori4.out");
int s,i,n,p,a;
int main()
{
    f>>n;
    s=1;
    p=1;
    for(i=1;i<=n;i++)
    {
        a=s;
        s+=p;
        p=a;
        s%=9001;
    }
    g<<s-1;
}
