#include <iostream>
#include <fstream>
using namespace std;
int v[20],n;
ifstream f("permutari.in");
ofstream g("permutari.out");
inline bool cond(int i,int x)
{
    int j;
    for(j=1;j<i;j++)
        if(x==v[j])
        return 0;
    return 1;
}
void bkt(int i)
{
    int j;
    if(i==n+1)
    {
        for(j=1;j<=n;j++)
            g<<v[j]<<' ';
        g<<'\n';
    }
    else
    for(j=1;j<=n;j++)
    if(cond(i,j))
    {
        v[i]=j;
        bkt(i+1);
    }
}
int main()
{
    f>>n;
    bkt(1);
}
