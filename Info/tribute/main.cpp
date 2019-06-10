#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define nmax (int) 5e4+10

ifstream fin("tribute.in");
ofstream fout("tribute.out");

vector <pair<int,int> > v;
int d1[nmax];
int d2[nmax];
int n,x,y,i;

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.s<b.s;
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    fin>>n>>x>>y;
    for(i=1; i<=n; ++i)
    {
        int a,b;
        fin>>a>>b;
        v.pb(mp(a,b));
    }
    sort(v.begin(),v.end());
    int ansx = 1e9, ansy = 1e9;
    int curr = 0;
    int index = 0;
    for(i=1; i<=5e4; ++i)
    {
        while(index < v.size() && v[index].f<i)
            ++curr,++index;
        d1[i]=d1[i-1]+curr;
    }

    index = v.size()-1;
    curr = 0;
    for(i=5e4; i>=0; --i)
    {
        while(index >= 0 && v[index].f>i)
            ++curr,--index;
        d2[i]=d2[i+1]+curr;
    }

    for(i=0; i<=5e4-x; ++i)
        if(ansx>d1[i]+d2[i+x])
            ansx = d1[i]+d2[i+x];

    memset(d1,0,sizeof(d1));
    memset(d2,0,sizeof(d2));
    sort(v.begin(),v.end(),cmp);

    index = 0,curr = 0;
    for(i=1; i<=5e4; ++i)
    {
        while(index < v.size() && v[index].s<i)
            ++curr,++index;
        d1[i]=d1[i-1]+curr;
    }

    index = v.size()-1;
    curr = 0;
    for(i=5e4; i>=0; --i)
    {
        while(index >= 0 && v[index].s>i)
            ++curr,--index;
        d2[i]=d2[i+1]+curr;
    }

    for(i=0; i<=5e4-y; ++i)
        if(ansy>d1[i]+d2[i+y])
            ansy = d1[i]+d2[i+y];

    fout<<ansx+ansy;
}
