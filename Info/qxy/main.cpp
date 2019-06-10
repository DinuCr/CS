#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("qxy.in");
ofstream fout("qxy.out");

struct sir
{
    int v[1012];
};

sir v[110];
int w[10010];
int first[10010];
int last[10010];
int n,k,p,a,b,ans,i,j;

int main()
{
    fin>>n;
    k = sqrt(n);
    int curr = 1;
    for(i=1; i<=n; ++i)
    {
        if(i%k==0)
        {
            v[curr].v[0]+=v[curr-1].v[0];
            for(j=1; j<=1000; ++j)
                v[curr].v[j]+=v[curr].v[j-1]+v[curr-1].v[j]-v[curr-1].v[j-1];
            ++curr;
        }
        int x;
        fin>>x;
        w[i]=x;
        ++v[curr].v[x];
        first[i]=i/k*k;
        last[i]=min((i/k+1)*k-1,n);
    }
    v[curr].v[0]+=v[curr-1].v[0];
    for(j=1; j<=1000; ++j)
        v[curr].v[j]+=v[curr].v[j-1]+v[curr-1].v[j]-v[curr-1].v[j-1];
    int q,x,y;
    fin>>q;
    while(q--)
    {
        fin>>i>>j>>x>>y;
        a = i/k+2;
        b = j/k;
        if(a<=b)
        {
            if(x!=0)
                ans = v[b].v[y]-v[b].v[x-1]-v[a-1].v[y]+v[a-1].v[x-1];
            else
                ans = v[b].v[y]-v[a-1].v[y];
        }
        else
            ans = 0;
        if(a-2==b)
        {
            for(int p = i; p<=j; ++p)
                if(w[p]<=y && w[p]>=x)
                    ++ans;
        }
        else
        {
            for(int p = i; p<=last[i]; ++p)
                if(w[p]<=y && w[p]>=x)
                    ++ans;
            for(int p = max(first[j],last[i]+1); p<=j; ++p)
                if(w[p]<=y && w[p]>=x)
                    ++ans;
        }
        fout<<ans<<'\n';
    }
}
