#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("carnati.in");
ofstream fout("carnati.out");

struct str
{
    int t,pret;
};

bool compare(str a,str b)
{
    return a.t<b.t;
}

str v[3000];
int n,c,i,s,mx,t1,a,b,k,p;

int main()
{
    fin>>n>>c;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i].t>>v[i].pret;
    }
    sort(v+1,v+n+1,compare);
    mx=0;
    for(k=1; k<=n; ++k)
    {
        p=v[k].pret;
        s=0;
        for(i=1; i<=n; ++i)
        {
            s-=c*(v[i].t-v[i-1].t);
            if(s<0)
                s=0;
            if(p<=v[i].pret)
                s+=p;
            mx=max(mx,s-c);
        }
    }
    fout<<mx;
}
