#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

ifstream fin("desen.in");
ofstream fout("desen.out");

#define nmax 1100

struct muchie
{
    int a,b;
    double l;
};
struct punct
{
    int x,y;
};
punct v[nmax];
muchie muchii[nmax*nmax];
muchie ans[nmax];
int r[nmax];
int a,b,n,i,nr,k,j;
double s;

double dist(punct a,punct b)
{
    return (double)sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline int compare(const muchie &a,const muchie &b)
{
    return a.l<b.l;
}

int root(int x)
{
    if(!r[x])
        return x;
    r[x]=root(r[x]);
    return r[x];
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i].x>>v[i].y;
        k=0;
        for(j=1; j<i; ++j)
            {
                ++k;
                muchii[k].a=j;
                muchii[k].b=i;
                muchii[k].l=dist(v[i],v[j]);
            }
        for(j=1; j<i-1; ++j)
        {
            ++k;
            muchii[k]=ans[j];
        }
        for(j=1; j<=i; ++j)
            r[j]=0;
        nr=0;
        s=0;
        sort(muchii+1,muchii+k+1,compare);
        for(j=1; j<=k; ++j)
        {
            if(root(muchii[j].a)!=root(muchii[j].b))
            {
                r[root(muchii[j].a)]=root(muchii[j].b);
                ++nr;
                ans[nr]=muchii[j];
                s+=ans[nr].l;
                if(nr==i-1)
                    break;
            }
        }
        fout<<setprecision(6)<<fixed<<s<<'\n';
    }
}
