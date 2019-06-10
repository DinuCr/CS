#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

long long v[510];
long long w[510];
long long n,t,ans,k,i;

void remove_best()
{
    long long mn = 1e9;
    long long poz = 2;
    for(long long i=2; i<=n; ++i)
    {
        long long x = (v[i]-v[i-1])*(w[i]-w[i-1]);
        if(mn>=x)
        {
            mn=x;
            poz=i;
        }
    }
    int a = v[poz-1];
    for(long long i=poz-1; i<n; ++i)
    {
        v[i]=v[i+1];
        w[i]=w[i+1];
    }
    v[poz-1]=a;
    --n;
    ans+=mn;
}

int main()
{
    fin>>t>>k>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
        w[i]=i;
        ans+=t-v[i];
    }
    long long x = n;
    while(x>k)
    {
        --x;
        remove_best();
    }
    fout<<ans;
}
