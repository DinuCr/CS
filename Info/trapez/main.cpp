#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream f("trapez.in");
ofstream g("trapez.out");

typedef struct coord
{
    int x,y;
};

coord v[1100];
long double w[1000100];
int n,i,j,nr,l,r,m;

int main()
{
    f>>n;
    for(i=1; i<=n; ++i)
        f>>v[i].x>>v[i].y;
    for(i=1; i<n; ++i)
        for(j=i+1; j<=n; ++j)
            if(v[i].x-v[j].x!=0)
                w[m++]=(long double)(v[i].y-v[j].y)/(v[i].x-v[j].x);
    nr=0;
    sort(w,w+m);
    while(l<m)
    {
        r=l;
        while(w[r+1]==w[r])
            ++r;
        nr+=(r-l)*(r-l+1)/2;
        l=r+1;
    }
    g<<nr;
}
