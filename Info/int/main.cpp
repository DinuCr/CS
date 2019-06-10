#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("int.in");
ofstream g("int.out");

typedef struct nod
{
    long long f,s;
};

nod v[55000],l;
long long n,nr,i;

bool compare(nod a, nod b)
{
    return a.s<b.s;
}

int main()
{
    f>>n;
    for(i=1; i<=n; ++i)
        f>>v[i].f>>v[i].s;
    sort(v+1,v+n+1,compare);
    l=v[1];
    nr=1;
    for(i=2; i<=n; )
    {
        while(v[i].f<l.f && i<n)
        {
            ++i;
        }
        if(v[i].f>=l.s)
        {
            ++nr;
            l=v[i];
            ++i;
        }
        else
        ++i;
    }
    g<<nr;
}
