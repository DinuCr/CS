#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("euler.in");
ofstream g("euler.out");

#define nmax 262200
#define ndat 524300

vector <int> v[nmax];
vector <int> t;

int w[ndat];
int q[nmax];

int n,m,i,nr,ok;

int main()
{
    f>>n;
    i=1;
    while(f>>w[i])
        ++i;
    m=i-1;
    for(i=2; i<=m; ++i)
    {
        if(t.size())
        {
            if(t.back()!=w[i])
            {
                t.push_back(w[i-1]);
                q[w[i]]=t.back();
            }
            else
                t.pop_back();
        }
        else
        {
            t.push_back(w[i-1]);
            q[w[i]]=w[i-1];
        }
    }
    ok=1;
    if(t.size())
        ok=0;
    else
    {
        for(i=1; i<=n; ++i)
            if(q[i]==0)
                nr++;
        if(nr>1 || nr==0)
            ok=0;
    }
    if(ok)
    {
        g<<"DA\n";
        for(i=1; i<=n; ++i)
            g<<q[i]<<' ';
    }
    else
        g<<"NU";
}
