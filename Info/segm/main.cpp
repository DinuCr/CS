#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("segm.in");
ofstream fout("segm.out");

#define mp make_pair
#define pb push_back
#define f first
#define s second

vector <pair<int,int> > v;
vector <int> ans;
int n,i,l1,l2;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.s!=b.s)
        return a.s<b.s;
    return a.f>b.f;
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        int a,b;
        fin>>a>>b;
        v.pb(mp(a,b));
    }
    sort(v.begin(),v.end(),cmp);
    l1=l2=0;
    for(i=0; i<n; ++i)
    {
        if(v[i].f<=l1)
            continue;
        else
        if(v[i].f<=l2)
        {
            l1=l2;
            l2=v[i].s;
            ans.pb(l2);
        }
        else
        {
            l1=v[i].s-1;
            l2=v[i].s;
            ans.pb(l1);
            ans.pb(l2);
        }
    }
    fout<<ans.size()<<'\n';
    sort(ans.begin(),ans.end());
    for(i=0; i<ans.size(); ++i)
        fout<<ans[i]<<' ';
}
