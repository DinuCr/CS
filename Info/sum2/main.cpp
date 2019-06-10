#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream fin("sum2.in");
ofstream fout("sum2.out");

deque <int> d;
int v[100100];
int n,k,mx,a,b,i;

int main()
{
    fin>>n>>a>>b;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
        v[i]+=v[i-1];
    }
    mx=-1000000000;
    for(i=1; i<=n; ++i)
    {
        if(d.size() && i-d.front()>b)
            d.pop_front();
        if(i-a>0)
        {
            int x=i-a;
            while(d.size() && v[x]<v[d.back()])
                d.pop_back();
            d.push_back(x);
        }
        if(d.size())
            mx=max(mx,v[i]-v[d.front()]);
    }
    fout<<mx;
}
