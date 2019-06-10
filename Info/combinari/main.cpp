#include <iostream>
#include <fstream>
using namespace std;
ifstream f("combinari.in");
ofstream g("combinari.out");
int n,k,v[20];
inline bool cond(int j,int x)
{
    int i;
    for(i=1; i<j; i++)
        if(v[i]>=x)
            return 0;
    return 1;
}
void bkt (int j)
{
    int i;
    if(k+1==j)
    {
        for(i=1; i<=k; i++)
            g<<v[i]<<' ';
        g<<'\n';
    }
    else
        for(i=1; i<=n; i++)
            if(cond(j,i))
            {
                v[j]=i;
                bkt(j+1);
            }
}
int main()
{
    f>>n>>k;
    bkt(1);
}
