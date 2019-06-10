#include <iostream>
#include <algorithm>
#include <fstream>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

ifstream fin("input.txt");
ofstream fout("output.txt");

tr1::unordered_map <long long,long long> m;
long long n,i,nr;
long long ans,x;

int main()
{
    long long k;
    fin>>n>>k;
    for(i=1; i<=n; ++i)
    {
        fin>>x;
        ++x;
        if(m[x]!=0)
            ans +=1LL*m[x]-1LL;
        else
        {
            ++nr;
            m[x]=nr;
            ans+=nr-1LL;
        }
    }
    fout<<ans;
}
