#include <iostream>
#include <deque>
#include <fstream>
using namespace std;

ifstream fin("vila2.in");
ofstream fout("vila2.out");

deque <int> d;
deque <int> dp;
int v[100100];
int n,i,k,mx;

int main()
{
    fin>>n>>k;
    for(i=1; i<=n; ++i)
        fin>>v[i];

    for(i=1; i<=n; ++i)
    {
        while(d.size() && i-d.front()>k)
            d.pop_front();
        while(d.size() && v[d.back()]>v[i])
            d.pop_back();
        d.push_back(i);

        while(dp.size() && i-dp.front()>k)
            dp.pop_front();
        while(dp.size() && v[dp.back()]<v[i])
            dp.pop_back();
        dp.push_back(i);

        if(i>=k)
            mx=max(mx,v[dp.front()]-v[d.front()]);
    }
    fout<<mx;
}
