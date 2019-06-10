#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("aiacubiti.in");
ofstream fout("aiacubiti.out");

#define mp make_pair
#define f first
#define s second

vector <pair<int,int> > curr;
int q[100010];
int v[1048577];
int w[20][1048577];

int main()
{
    int n,i,p[25],x,a,b;
    p[0]=1;
    for(i=1; i<=20; ++i)
        p[i]=p[i-1]<<1;
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>q[i];
    int ans = 0;
    for(a=0; a<19; ++a)
    {
        for(b=a+1; b<20; ++b)
        {
            for(i=1; i<=n; ++i)
            {
                int x = q[i]^p[a]^p[b];
                ans+=v[x]-w[b][x]-w[a][x];
                curr.push_back(mp(x,b));
            }
        }
        for(auto it:curr)
            ++v[it.f],++w[it.s][it.f];
        curr.clear();
    }
    fout<<ans/6;
}
