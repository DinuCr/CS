#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("maxk.in");
ofstream g("maxk.out");
int v[100010],v2[100010],w[1000010];
vector <int> p;
int n,k,i,mn,nr;
bool verif()
{
    for(int i=0;i<p.size();i++)
        if(v[p[i]]>v2[p[i]])
        return 0;
    return 1;
}
int main()
{
    f>>n>>k;
    for(i=1;i<=n;i++)
    {
        f>>w[i];
        v[w[i]]++;
    }
    for(i=1;i<=100000;i++)
    {
        v[i]-=k;
        if(v[i]>0)
            p.push_back(i);
        else
            v[i]=0;
    }
    nr=0;mn=100000000;
    for(i=1;i<=n;i++)
    {
        v2[w[i]]++;
        if(v2[w[i]]>=v[w[i]])
        {
            if(verif())
            {
                while(v2[w[i-nr]]>v[w[i-nr]])
                {
                    v2[w[i-nr]]--;
                    nr--;
                }
                mn=min(mn,nr+1);
                nr++;
            }
            else
            nr++;
        }
        else
        nr++;
    }
    g<<mn;
}
