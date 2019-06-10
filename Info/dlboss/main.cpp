#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;

ifstream fin("dlboss.in");
ofstream fout("dlboss.out");

#define mp make_pair
#define f first
#define s second
#define nmax 100010

priority_queue <int> h;
int d[nmax];
int w[nmax];
pair<pair<int,int>,int> v[nmax];

bool cmp(const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b)
{
    if(a.f.s==b.f.s)
        return a.f.f>b.f.f;
    return a.f.s<b.f.s;
}

int main()
{
    int n,t,i;
    fin>>n>>t;
    for(i=1; i<=n; ++i)
        fin>>v[i].f.f>>v[i].f.s,v[i].s=i;
    sort(v+1,v+n+1,cmp);
    int curr = 0;
    int nr = 0;
    for(i=n; i>0; --i)
    {
        if(v[i].f.s==v[i+1].f.s)
            d[i]=d[i+1];
        else
        {
            while(curr>t)
            {
                curr-=h.top();
                h.pop();
                --nr;
            }
            d[i]=nr;
            curr+=v[i].f.f;
            h.push(v[i].f.f);
            ++nr;
        }
    }
    for(i=1; i<=n; ++i)
        w[v[i].s]=i;
    for(i=1; i<=n; ++i)
        fout<<d[w[i]]<<'\n';
}
