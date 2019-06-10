#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

struct fan
{
    int n,q;
    char s[25];
};

fan v[1010];
int n,t,i;

bool compare(fan a,fan b)
{
    int mn = min(a.n,b.n);
    for(int i=0; i<mn; ++i)
        if(a.s[i] != b.s[i])
            return a.s[i]<b.s[i];
    return a.n<b.n;
}

bool cmp(fan a,fan b)
{
    if(a.q==b.q)
        return compare(a,b);
    return a.q>b.q;
}

int main()
{
    cin>>n>>t;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i].s>>v[i].q;
        v[i].n=strlen(v[i].s);
    }
    sort(v+1,v+n+1,cmp);
    for(i=1; i<=t; ++i)
        cout<<v[i].s<<'\n';
}
