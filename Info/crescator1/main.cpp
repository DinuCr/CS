#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("crescator1.in");
ofstream fout("crescator1.out");

#define nmax 100100

int v[nmax];
int w[nmax];
int i,n;

inline int sc(int a)
{
    int ans = 0;
    while(a)
    {
        ans+=a%10;
        a/=10;
    }
    return ans;
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    w[1]=v[1];
    for(i=2; i<=n; ++i)
        w[i]=w[i-1]+sc(w[i-1]);
    int ans = 0;
    for(i=1; i<=n; ++i)
        ans+=binary_search(w+1,w+n+1,v[i]);
    fout<<ans;
}
