#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("apm.in");
ofstream g("apm.out");

struct muchie
{
    int a,b,c;
};

int t[200100],n,m,i,c;
muchie v[400100];
int r[400100],k;

int root(int x)
{
    if(!t[x])
        return x;
    t[x]=root(t[x]);
    return t[x];
}

bool compare(muchie a,muchie b)
{
    return a.c<b.c;
}

int main()
{
    f>>n>>m;
    for(i=0; i<m; ++i)
        f>>v[i].a>>v[i].b>>v[i].c;

    sort(v,v+m,compare);

    int a,b;
    for(i=0; i<m; ++i)
    {
        a=root(v[i].a);
        b=root(v[i].b);
        if(a!=b)
        {
            c+=v[i].c;
            t[a]=b;
            r[k++]=i;
        }
    }
    g<<c<<'\n'<<k<<'\n';
    for(i=0; i<k; ++i)
        g<<v[r[i]].a<<' '<<v[r[i]].b<<'\n';
}
