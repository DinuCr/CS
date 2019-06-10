#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("permutare2.in");
ofstream fout("permutare2.out");

#define nmax 100010

long long v[nmax],n,m,i,x,curr,st,dr,ans,a;

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        fin>>x;
    v[0]++;
    for(i=1; i<m; ++i)
    {
        fin>>x;
        v[x%n]++;
    }
    for(i=1; i<=n/2; ++i)
        curr+=v[i]*i,dr+=v[i];
    for(i=n/2+1; i<n; ++i)
        curr+=v[i]*(n-i),st+=v[i];
    ans = curr;
    a = n/2;
    for(i=1; i<n; ++i)
    {
        ++a;
        if(a==n)
            a=0;
        curr = curr - v[i] + st + v[i-1] - dr + v[i];
        st=st - v[a] + v[i-1];
        dr=dr - v[i] + v[a];
        ans = min(ans,curr);
    }
    fout<<ans;
}
