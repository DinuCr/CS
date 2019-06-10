#include <iostream>
#include <deque>
#include <fstream>
#include <stdio.h>
using namespace std;
int n,k,v[500010];
int i,mx,x;
ifstream f("secventa.in");
FILE *g=fopen("secventa.out","w");
int w[500010],d,s;
int main()
{
    f>>n>>k;
    mx=-3000000;
    for(i=1; i<=n; i++)
        f>>v[i];
        d=0;
        s=1;
    for(i=1; i<=n; i++)
    {
        while(d>=s && v[w[d]]>v[i])
            d--;
        w[++d]=i;
        if(w[s]==i-k)
            s++;
        if(i>=k)
            if(v[w[s]]>mx)
            {
                mx=v[w[s]];
                x=i-k;
            }
    }
    fprintf(g,"%d %d %d",x+1,x+k,mx);
}
