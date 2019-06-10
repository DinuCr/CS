#include <iostream>
#include <fstream>

using namespace std;

ifstream f("modulo.in");
ofstream g("modulo.out");

long long a,b,c;

long long pow(long long a,long long b)
{
    if(b==1)
        return a;
    if(b&1)
        return (a*pow(a,b-1))%c;
    return pow(a*a%c,b/2);
}

int main()
{
    f>>a>>b>>c;
    g<<pow(a,b);
}
