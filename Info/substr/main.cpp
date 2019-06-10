#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <deque>

using namespace std;

ifstream fin("substr.in");
ofstream fout("substr.out");

#define mp make_pair
#define f first
#define s second

deque <int> q;
pair<pair<int,int>,int> curr[17000];
char v[17000];
int w[18][17000];
int ord[17000];
int alike[17000];
int n,i,k,z;

int cmp(int a,int b)
{
    int cnt = 0;
    while(b<n)
    {
        if(v[a]!=v[b])
            return cnt;
        else
            ++a,++b,++cnt;
    }
    return cnt;
}

inline int exp(int i,int k)
{
    return min(i+(1<<k),n+1);
}

int main()
{
    fin>>n>>z;
    fin>>v;
    for(i=0; i<n; ++i)
        w[0][i]=v[i];
    for(k=1; k<=15; ++k)
    {
        for(i=0; i<n; ++i)
            curr[i]=mp(mp(w[k-1][i],w[k-1][exp(i,k-1)]),i);
        sort(curr,curr+n);
        int nr = 0;
        for(i=0; i<n; ++i)
            if(i>0 && curr[i].f==curr[i-1].f)
                w[k][curr[i].s]=nr;
            else
                w[k][curr[i].s]=++nr;
    }
    for(i=0; i<n; ++i)
        ord[i]=curr[i].s;
    for(i=1; i<n; ++i)
        alike[i]=cmp(ord[i-1],ord[i]);
    if(z==1)
    {
        fout<<n;
        return 0;
    }
    int ans = 0;
    for(i=1; i<n; ++i)
    {
        while(q.size() && q.front()<=i-z+1)
            q.pop_front();
        while(q.size() && alike[q.back()]>alike[i])
            q.pop_back();
        q.push_back(i);
        if(i>=z-1)
            ans = max(ans,alike[q.front()]);
    }
    fout<<ans;
}
