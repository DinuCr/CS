#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("divide.in");
ofstream fout("divide.out");

#define ll long long
#define nmax (int) 1e6+10

ll v[nmax];
ll n,x,i,c,curr,curr2;

int main()
{
    ll sum = 0;
    fin>>n>>x>>c;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
        sum+=v[i];
    }
    ll ans = 0,p2;
    for(int p=1; p<=x; ++p)
    {
        ans+=abs(p*c-sum);
    }
    fout<<ans%666013;
}
