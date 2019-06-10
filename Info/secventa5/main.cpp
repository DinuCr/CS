#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("secv5.in");
ofstream fout("secv5.out");

#define f first
#define s second
const long long prim = 666013;
#define nmax 1200000

vector < pair <long long,long long> > h[prim];
long long v[nmax];
long long d[nmax];
long long fr[nmax];
long long n,k,i,l,u,x,number,nr,ans,s;

void push(long long x,long long k)
{
     h[x%prim].push_back(make_pair(x,k));
}

long long exists(long long x)
{
    long long mod = (x % prim);
    for(long long i=0; i<h[mod].size(); ++i)
        if(h[mod][i].f==x)
            return h[mod][i].s;
    return -1;
}

int main()
{
    fin>>n>>l>>u;
    k=0;
    for(i=1; i<=n; ++i)
    {
        fin>>x;
        number = exists(x);
        if(number > 0)
        {
            v[i]=number;
        }
        else
        {
            ++k;
            push(x,k);
            v[i]=k;
        }
    }
    s=1;
    nr=0;
    for(i=1; i<=n; ++i)
    {
        fr[v[i]]++;
        if(fr[v[i]]==1)
        {
            ++nr;
            while(nr>l-1)
            {
                fr[v[s]]--;
                if(fr[v[s]]==0)
                    --nr;
                ++s;
            }
        }
        d[i]=s;
    }
    for(i=s; i<=n; ++i)
        --fr[v[i]];
    s=1;
    nr=0;
    for(i=1; i<=n; ++i)
    {
        fr[v[i]]++;
        if(fr[v[i]]==1)
        {
            ++nr;
            while(nr>u)
            {
                fr[v[s]]--;
                if(fr[v[s]]==0)
                    --nr;
                ++s;
            }
        }
        ans+=(d[i]-s);
    }
    fout<<ans;
}
