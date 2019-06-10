#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

ifstream fin("trenul.in");
ofstream fout("trenul.out");

#define nmax (int)1e5+100

int used[nmax];

vector <pair<int,int> > v;
vector <pair<pair<int,int>,pair<int,int> > > ans;

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.f>b.f;
}

bool cmp2(const pair<pair<int,int>,pair<int,int> > &a, const pair<pair<int,int>,pair<int,int> > &b)
{
    return a.s.s<b.s.s;
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int n,q,x;

    fin>>n>>q;

    for(int i=1; i<=q; ++i)
    {
        fin>>x;
        v.pb(mp(x,i));
    }
    sort(v.begin(),v.end(),cmp);
    int curr = 1;
    int last_empty = 0;
    for(auto it:v)
    {
        if(it.f==3)
        {
            for(int i=curr; i<curr+it.f; ++i)
                used[i]=1;
            curr+=it.f;
            ans.pb(mp(mp(curr-3,curr-2),mp(curr-1,it.s)));
        }
        else
        if(it.f==1)
        {
            if(last_empty)
            {
                ans.pb(mp(mp(last_empty,0),mp(0,it.s))),last_empty=0;
                continue;
            }
            for(int i=curr; i<curr+it.f; ++i)
                used[i]=1;
            curr+=it.f;
            ans.pb(mp(mp(curr-1,0),mp(0,it.s)));
        }
        else
        {
            if(curr%2==0)
            {
                last_empty=curr;
                ++curr;
            }
            for(int i=curr; i<curr+it.f; ++i)
                used[i]=1;
            curr+=it.f;
            ans.pb(mp(mp(curr-2,curr-1),mp(0,it.s)));
        }
    }
    sort(ans.begin(),ans.end(),cmp2);
    for(auto it:ans)
    {
        fout<<it.f.f<<' ';
        if(it.f.s)
            fout<<it.f.s<<' ';
        if(it.s.f)
            fout<<it.s.f;
        fout<<'\n';
    }
}
