#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("dictree.in");
ofstream fout("dictree.out");

int n,i,j,ans;

struct sir
{
    char s[120];
    int sz;
};

sir v[25200];

bool cmp(sir a,sir b)
{
    int x = min(a.sz,b.sz);
    for(int i=0; i<=x; ++i)
        if(a.s[i]!=b.s[i])
            return a.s[i]<b.s[i];
    return a.s[0]<b.s[0];
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i].s;
        v[i].sz=strlen(v[i].s);
    }
    sort(v+1,v+n+1,cmp);
    for(i=1; i<=n; ++i)
    {
        int x = min(v[i].sz,v[i-1].sz);
        for(j=0; j<x; ++j)
            if(v[i].s[j]!=v[i-1].s[j])
                break;
        ans+=v[i].sz-j;
    }
    fout<<ans+1;
}
