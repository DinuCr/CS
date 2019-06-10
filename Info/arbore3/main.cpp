#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

#define nmax 1000100
#define mp make_pair
#define f first
#define s second

const int hashv = 666013;

vector <pair<int,int> > h[666020];
vector <int> v[nmax];
int d[nmax];
int ans,sum,i,a,n;

inline int abs(int x)
{
    if(x<0)
        return -x;
    return x;
}

void adauga(int x)
{
    int i;
    int nr=abs(x)%hashv;
    for(i=0; i<h[nr].size(); ++i)
        if(h[nr][i].f==x)
        {
            ++h[nr][i].s;
            return ;
        }
    h[nr].push_back(mp(x,1));
}

void scoate(int x)
{
    int i;
    int nr=abs(x)%hashv;
    for(i=0; i<h[nr].size(); ++i)
        if(h[nr][i].f==x)
        {
            --h[nr][i].s;
            if(h[nr][i].s==0)
            {
                swap(h[nr][i],h[nr][h[nr].size()-1]);
                h[nr].pop_back();
            }
            return ;
        }
}

int gaseste(int x)
{
    int i;
    int nr=abs(x)%hashv;
    for(i=0; i<h[nr].size(); ++i)
        if(h[nr][i].f==x)
        {
            return h[nr][i].s;
        }
    return 0;
}

void df(int x,int p)
{
    p+=d[x];
    adauga(p);
    ans+=gaseste(p-sum);
    for(int i=0; i<v[x].size(); ++i)
    {
        df(v[x][i],p);
    }
    scoate(p);
}

int main()
{
    freopen("arbore3.in","r",stdin);
    freopen("arbore3.out","w",stdout);

    scanf("%d%d%d%d",&n,&sum,&a,&d[1]);
    for(i=2; i<=n; ++i)
    {
        scanf("%d%d",&a,&d[i]);
        v[a].push_back(i);
    }
    adauga(0);
    df(1,0);
    printf("%d",ans);
}
