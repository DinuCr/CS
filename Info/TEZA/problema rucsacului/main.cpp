#include <iostream>
#include <fstream>
using namespace std;
ifstream f("rucsac.in");
ofstream p("rucsac.out");
int r[10010],j,g,G,n,i,v;
int main()
{
    f>>n>>G;
    for(i=1;i<=n;i++)
    {
        f>>g>>v;
        for(j=G;j>=0;j--)
            {
                if(j+g<=G && r[j+g]<r[j]+v)
                r[j+g]=r[j]+v;
            }
        if(g<=G && r[g]<v)
            r[g]=v;
    }
    p<<r[G];
}
