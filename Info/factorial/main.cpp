#include <iostream>
#include <fstream>

using namespace std;

ifstream f("fact.in");
ofstream g("fact.out");

#define nmax 4000001000

long long p,x;

long long zeros(long long x)
{
    long long i,nr=0;
    for(i=5; i<=x; i*=5)
        nr+=x/i;
    return nr;
}

long long bs(long long s, long long d, long long x)
{
    if(s>=d)
        return s;
    else
    {
        long long m=zeros((s+d)/2);
        if(x==m)
            return (s+d)/2;
        else
        if(x<m)
            return bs(s,(s+d)/2-1,x);
        return bs((s+d)/2+1,d,x);
    }
}

int main()
{
    f>>p;

    x = bs(1,400000100,p);

    if(zeros(x) == p)
    {
        while(x%5!=0 && x>1)
            --x;
        g<<x;
    }
    else
        g<<-1;

}
