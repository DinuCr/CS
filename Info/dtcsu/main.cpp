#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("dtcsu.in");
ofstream fout("dtcsu.out");

#define mod 8191

vector <long long> h[mod];
long long i,q,ans,x;

void add(long long x)
{
    h[x%mod].push_back(x);
}

bool is(long long x)
{
    int p = x%mod;
    for(int i=0; i<h[p].size(); ++i)
        if(h[p][i]==x)
            return 1;
    return 0;
}

int main()
{
    for(i=1; i<=276997; ++i)
    {
        fin>>x;
        if(x&1LL)
            add(x);
    }
    fin>>q;
    while(q--)
    {
        fin>>x;
        if(x)
            x=x/(x&(-x));
        if(is(x))
            ++ans;
    }
    fout<<ans;
}
