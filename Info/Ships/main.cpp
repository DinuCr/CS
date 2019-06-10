#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("vapoare.in");
ofstream fout("vapoare.out");

#define nmax (int) 5e4 +10
#define f first
#define s second
#define mp make_pair

int ans[nmax];
vector <pair<pair<unsigned short,unsigned short> ,unsigned short> > v;
int t[nmax];

int root(int x)
{
    if(!t[x])
        return x;
    t[x]=root(t[x]);
    return t[x];
}

int cmp(pair<pair<unsigned short,unsigned short>,unsigned short> a, pair<pair<unsigned short,unsigned short>,unsigned short> b)
{
    return a.s>b.s;
}

int main()
{
    int n,m,q,i;
    fin>>n>>m>>q;
    for(i=1; i<=m; ++i)
    {
        int a,b,c;
        fin>>a>>b>>c;
        v.push_back(mp(mp(a,b),c));
    }
    sort(v.begin(),v.end(),cmp);
    int curr = n;
    int l = 5e4;
    for(auto it:v)
    {
        for(i=l; i>it.s; --i)
            ans[i]=curr;
        if(root(it.f.f)!=root(it.f.s))
        {
            t[root(it.f.f)]=root(it.f.s);
            --curr;
        }
        l=it.s;
    }
    for(i=l; i>0; --i)
        ans[i]=curr;
    while(q--)
    {
        int x;
        fin>>x;
        fout<<ans[x]<<'\n';
    }
}
