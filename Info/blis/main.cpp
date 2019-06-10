#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream fin("blis.in");
ofstream fout("blis.out");

const int inf = 2000000000;

#define mp make_pair
#define f first
#define s second

vector <pair<int,int> > up[100010];
char v[100010];
int d[100010];
int k;

int main()
{
    fin>>k>>v+1;
    int n = strlen(v+1)+1,j,i,ans,l=0;
    int curr = 0;
    for(i=1; i<min(n,k+1); ++i)
        curr = (curr<<1) + (v[i]-'0');
    ans = curr;
    for(i=k+1; i<n; ++i)
    {
        curr = (curr<<1) + (v[i]-'0');
        curr %= (1<<k);
        ans = max(ans,curr);
    }
    fout<<ans<<'\n';
    for(i=1; i<=n; ++i)
        d[i]=inf;
    for(i=1; i<n; ++i)
    {
        curr = 0;
        int lim = min(n,i+k);
        for(j=i; j<lim; ++j)
        {
            curr = curr<<1 | (v[j]-'0');

            int z;
            for(z=1; z<l; z<<=1);

            ans = 1;
            for( ; z; z>>=1)
                if(ans+z<=l+1 && curr>d[ans+z-1])
                    ans+=z;
            if(curr<d[ans])
                up[j].push_back(mp(ans,curr));
        }
        for(auto it:up[i])
            {
                d[it.f]=min(d[it.f],it.s);
                l=max(l,it.f);
            }
    }
    fout<<l;
}
