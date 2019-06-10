#include <iostream>
#include <fstream>
using namespace std;
ifstream f("lgput.in");
ofstream g("lgput.out");
inline long long m(long long a)
{
    return a%1999999973;
}
long long n,p;
long long exp(long long n,long long p)
{
    if(p==1)
        return m(n);
    else
    if(p%2==0)
        return exp(m(n*n),p/2);
    return m(n*exp(n,p-1));
}
int main()
{
    f>>n>>p;
    n=m(n);
    g<<exp(n,p);
}
