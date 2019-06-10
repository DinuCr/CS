#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <pair<int,int> > v;
vector <int> curr;

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.s<b.s;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n,k,i;

    cin>>n>>k;
    for(i=1; i<=n; ++i)
    {
        int x,y;
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    sort(v.begin(),v.end(),cmp);
    for(auto it:v)
    {
        for(i=1; i<curr.size(); i<<=1);
        int j;
        for(j=0; i; i>>=1)
            if(j+i<curr.size() && curr[j+i-1]>=it.f)
                j+=i;
        if(curr.empty() || it.f<=curr[j])
            curr.pb(it.f);
        else
            curr[j]=it.f;
    }
    cout<<curr.size();
}
