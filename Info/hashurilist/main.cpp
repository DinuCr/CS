#include <iostream>
#include <list>
#include <fstream>
using namespace std;
ifstream f("hashuri.in");
ofstream g("hashuri.out");
list<int> v[666013];
list<int>::iterator j;
int n,i,ok,z,x,p;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>z;
        switch(x)
        {
        case 1:
            p=z%666013;
            ok=0;
            for(j=v[p].begin();j!=v[p].end();j++)
                if(*j==z)
                {
                    ok=1;
                    break;
                }
            if(!ok)
            v[p].push_back(z);
            break;
        case 2:
            p=z%666013;
            for(j=v[p].begin();j!=v[p].end();j++)
                if(z==*j)
                {
                    j=v[p].erase(j);
                    break;
                }
            break;
        case 3:
            p=z%666013;ok=0;
            for(j=v[p].begin();j!=v[p].end();j++)
                if(*j==z)
                {
                    ok=1;
                    break;
                }
            g<<ok<<'\n';
            break;
        }
    }
}
