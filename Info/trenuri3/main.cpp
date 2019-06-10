#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;

ifstream fin("trenuri3.in");
ofstream fout("trenuri3.out");

#define nmax 100010
#define mp make_pair
#define f first
#define s second

int ans[nmax];
int cap[nmax];
int oc[nmax];
vector <int> curr;
pair<int,int> tren[nmax];
pair<int,int> pas[nmax];
pair<int,int> p[nmax*2];
priority_queue <pair<int,int>,vector <pair<int,int> >, greater<pair<int,int> > >h;

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.f==b.f)
    {
        if(a.s*b.s<0)
            return a.s<b.s;
        if(a.s<0)
        {
            return pas[-a.s].f>pas[-b.s].f;
        }
    }
    return a.f<b.f;
}

int main()
{
    int n,m,i;
    fin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        fin>>tren[i].f>>cap[i];///statie,nr
        tren[i].s=i;
    }
    sort(tren+1,tren+n+1);
    for(i=1; i<=m; ++i)
    {
        fin>>pas[i].f>>pas[i].s;
        p[i<<1]=mp(pas[i].f,i);///coboara
        p[(i<<1)-1]=mp(pas[i].s,-i);///urca
    }
    sort(p+1,p+(m<<1)+1,cmp);
    int poz = p[m<<1].f;
    i = m<<1;
    int j = n;
    while(poz!=0)
    {
        while(j>0 && tren[j].f>=poz)
            curr.push_back(tren[j--].s);

        if(p[i].s>0)
        {
            if(ans[p[i].s] && oc[ans[p[i].s]]--==cap[ans[p[i].s]])
                curr.push_back(ans[p[i].s]);
        }
        else
        {
            if(curr.size()>0)
            {
                ans[-p[i].s]=curr.back();
                if(++oc[curr.back()]==cap[curr.back()])
                    curr.pop_back();
                h.push(mp(pas[-p[i].s].f,-p[i].s));
            }
            else if(!h.empty())
            {
                int leave = h.top().s;
                if(pas[leave].f<pas[-p[i].s].f)
                {
                    h.pop();
                    ans[-p[i].s]=ans[leave];
                    ans[leave]=0;
                    h.push(mp(pas[-p[i].s].f,-p[i].s));
                }
            }
        }
        poz = p[--i].f;
    }
    int rez = 0;
    for(i=1; i<=m; ++i)
        if(ans[i]!=0)
            ++rez;
    fout<<rez<<'\n';
    for(i=1; i<=m; ++i)
        fout<<ans[i]<<'\n';
}
