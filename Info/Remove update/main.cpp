#include <iostream>
#include <vector>

using namespace std;

#define mp make_pair
#define f first
#define s second
#define nmax (int)1e5+10

vector <pair<pair<int,int>,int> >q;
int v[nmax];
int ls[nmax];
int ld[nmax];

int main()
{
    int n,m,i,l=nmax,r=0,mx=0;
    cin>>n>>m;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        q.push_back(mp(mp(a,b),c));
        v[a]+=c;
        v[b+1]-=c;
    }
    for(i=1; i<=n; ++i)
        v[i]+=v[i-1],ls[i]=max(v[i],ls[i-1]),mx=max(mx,ls[i]);
    for(i=n; i>0; --i)
    {
        ld[i]=max(ld[i+1],v[i]);
        if(v[i]==mx)
        {
            l = min(l,i);
            r = max(r,i);
        }
    }
    int ans = mx;
    for(auto it:q)
        if(it.f.f<=l && it.f.s>=r)
            ans = min(ans,max(mx-it.s,max(ls[it.f.f-1],ld[it.f.s+1])));
    cout<<ans;
}
