#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("klsecv.in");
ofstream fout("klsecv.out");

#define mp make_pair
#define f first
#define s second
#define zeros(x) ((x^(x-1))&x)
#define nmax 20500

pair<pair<int,int>, int> curr[nmax];
pair<pair<int,int>,pair<int,int> > query[nmax];
int v[17][nmax];
char S[nmax];
int cnt[nmax];
int viz[nmax];
int poz[nmax];
int n,t,i,k;

inline int exp(int i,int j)
{
    return min(n,i+(1<<j));
}

void add(int poz,int x)
{
    for( ; poz<=n; poz+=zeros(poz))
        cnt[poz]+=x;
}

int compute(int poz)
{
    int ans = 0;
    for( ; poz>0; poz-=zeros(poz))
        ans+=cnt[poz];
    return ans;
}

bool cmp1(pair<pair<int,int>,pair<int,int> > a,pair<pair<int,int>,pair<int,int> > b)
{
    return a.f.s>b.f.s;
}

bool cmp2(pair<pair<int,int>,pair<int,int> > a,pair<pair<int,int>,pair<int,int> > b)
{
    return a.s.f<b.s.f;
}

int bs(int ls,int ld,int x)
{
    int m = (ls+ld)>>1;
    int a = compute(m);
    if(a==x && viz[m])
        return curr[m].s;
    if(a>x || (a==x && !viz[m]))
        return bs(ls,m-1,x);
    return bs(m+1,ld,x);
}

int main()
{
    fin>>t;
    while(t--)
    {
        fin>>S+1;
        n = strlen(S+1)+1;
        int kmax = log2(n)+1;
        for(i=1; i<n; ++i)
            v[0][i]=S[i];
        for(k=1; k<=kmax; ++k)
        {
            for(i=1; i<n; ++i)
                curr[i]=mp(mp(v[k-1][i],v[k-1][exp(i,k-1)]),i);
            sort(curr+1,curr+n);
            int nr = 0;
            for(i=1; i<n; ++i)
                if(i>1 && curr[i].f==curr[i-1].f)
                    v[k][curr[i].s]=nr;
                else
                    v[k][curr[i].s]=++nr;
        }
        memset(cnt, 0, sizeof(cnt));
        memset(viz, 0, sizeof(viz));
        int q;
        fin>>q;
        for(i=1; i<n; ++i)
            poz[curr[i].s]=i;
        for(i=1; i<=q; ++i)
            fin>>query[i].f.s>>query[i].f.f,query[i].s.f=i;
        sort(query+1,query+q+1,cmp1);
        int last = n-1;
        for(i=1; i<=q; ++i)
        {
            while(last>=query[i].f.s)
            {
                add(poz[n-last],1);
                viz[poz[n-last]]=1;
                last--;
            }
            query[i].s.s = bs(1,n-1,query[i].f.f);
        }
        sort(query+1,query+q+1,cmp2);
        for(i=1; i<=q; ++i)
            fout<<query[i].s.s<<'\n';
    }
}
