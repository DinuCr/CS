#include <iostream>
#include <fstream>
using namespace std;
ifstream f("in.in");
int i,i1,i2,n,nr,v[100];
int main()
{

    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i];
    }
    i1=1;
    while(!v[i1] && i1<=n)
        i1++;
    i2=n;
    if(i1<=n)
        nr++;
    while(!v[i2] && i2>0)
        i2--;
    if(i2>0)
        nr++;
    if(i1==i2)
        nr--;
    for(i=i1+1;i<i2;i++)
    {
        if(v[i])
            nr++;
        else
        if(!v[i+1])
            {
            while(!v[i])
                i++;
                i--;
            }
        else
            nr++;

    }
    cout<<nr;
}
