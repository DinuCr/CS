#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define zeros(x) (x ^ (x-1)) & x

int v[100100],n;

void add(int x, int quantity)
{
    int i;

    for (i = x; i <= n; i += zeros(i))
        v[i] += quantity;
}

int compute(int x)
{
    int i, ret = 0;

    for (i = x; i > 0; i -= zeros(i))
        ret += v[i];
    return ret;
}

int main()
{
    fin>>n;
    for(int i=1; i<=n; ++i)
    {
        int x;
        fin>>x;
        int ans = x - 1 - compute(x-1) + i - compute(x-1) ;
        fout<<ans-1<<' ';
        add(x,1);
    }
}
