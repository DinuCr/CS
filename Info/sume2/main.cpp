#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("sume2.in");
ofstream fout("sume2.out");

#define nmax 50010
#define ll long long

int v[nmax],i,n;
ll k;

bool check(int a)
{
    ll ans = 0;
    int curr = 0,j;

    for(int i=1; i<=n; ++i)
    {
        curr = 0;
        for(j=1; j<=n; j<<=1);

        for( ; j; j>>=1)
            if(curr+j<=n && v[i]+v[curr+j]<=a)
                curr+=j;
        ans+=curr;
    }

    return ans >= k;
}


int main()
{
    fin>>n>>k;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    sort(v+1,v+n+1);

    int ans = v[n]*2;
    for(i=1; i<=v[n]*2; i<<=1);

    for( ; i; i>>=1)
        if(ans-i>=0 && check(ans-i))
            ans-=i;

    fout<<ans;
}
