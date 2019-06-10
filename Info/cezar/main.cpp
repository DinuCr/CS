#include <list>
#include <queue>
#include <cstdio>

using namespace std;

#define nmax 10100
#define f first
#define s second
#define mp make_pair

priority_queue <pair<short,short>, vector <pair<short,short> >, greater <pair<short,short> > >q;
list <short> v[nmax];
short viz[nmax];
short n,k,i;
int ans;

void sterge(short t,short x)
{
    for(auto i=v[t].begin(); i!=v[t].end(); ++i)
        if(*i==x)
        {
            v[t].erase(i);
            return ;
        }
}

int main()
{
    freopen("cezar.in","r",stdin);
    freopen("cezar.out","w",stdout);
    scanf("%hd",&n);
    scanf("%hd",&k);
    for(i=1; i<n; ++i)
    {
        short a,b;

        scanf("%hd",&a);
        scanf("%hd",&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1; i<=n; ++i)
        if(v[i].size()==1)
            q.push(mp(0,i));
    ++k;
    short nod,t;
    for(i=n; i>k; --i)
    {
        nod = q.top().s;
        q.pop();
        t = *v[nod].begin();
        viz[t]+=viz[nod]+1;
        v[nod].pop_front();
        sterge(t,nod);
        if(v[t].size()==1)
            q.push(mp(viz[t],t));
    }
    for(i=1; i<=n; ++i)
        ans+=viz[i];
    printf("%d",ans);
}
