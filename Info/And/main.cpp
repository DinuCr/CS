#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

ifstream fin("and.in");
ofstream fout("and.out");

#define nmax (int) 1e5+10

int v[nmax];

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int n,i,j;

    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];

    int ans = 0;
    for(j=1; j<=32; ++j)
    {
        int curr = 0;
        for(i=1; i<=n; ++i)
            if(v[i]&(1<<j))
                ++curr;
            else
                ans=max(ans,curr),curr=0;
    }
    fout<<ans;
}
