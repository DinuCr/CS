#include <iostream>
#include <fstream>
#include <tr1/unordered_map>
#include <cstring>

using namespace std;
using namespace tr1;

ifstream fin("brazi.in");
ofstream fout("brazi.out");

#define mp make_pair
#define f first
#define s second

tr1::unordered_map <long long, int> h;
int v[12][2];
int f[12];
long long curr;

void df(int x)
{
    if(v[x][0])
    {
        curr=curr*10+1;
        df(v[x][0]);
    }
    if(v[x][1])
    {
        curr=curr*10+2;
        df(v[x][1]);
    }
    curr=curr*10+3;
}

int main()
{
    int t,n,a,b,c,i;
    fin>>t;
    while(t--)
    {
        fin>>n;
        memset(v, 0, sizeof(v));
        memset(f, 0, sizeof(f));
        for(i=1; i<n; ++i)
        {
            fin>>a>>b>>c;
            v[a][c]=b;
            f[b]=1;
        }
        for(i=1; i<=n; ++i)
            if(!f[i])
            {
                curr=0;
                df(i);
                fout<<h[curr]++<<'\n';
                break;
            }
    }
}
