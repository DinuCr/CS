#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("costuri.in");
ofstream fout("costuri.out");

#define nmax 100100
#define f first
#define s second

pair<int,pair<int,int> > v[nmax];
pair<int,pair<int,int> >x;
int n,i,q;

inline int cost(int x)
{
    if(x == 0)
        return 0;
    else
    {
        int ans = 1;
        while(x)
        {
            ans*=x%10;
            x/=10;
        }
        return ans;
    }
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i].s.s;
        v[i].s.f=i;
        v[i].f = cost(v[i].s.s);
    }
    sort(v+1,v+n+1);
    fin>>q;
    int poz;
    while(q--)
    {
        int a,b;
        fin>>a>>x.f;
        poz = lower_bound(v+1,v+n+1,x)-v-1;
        if(poz+a<=n && v[poz+a].f==x.f)
            fout<<v[poz+a].s.s<<'\n';
        else
            fout<<"-1\n";
    }
}
