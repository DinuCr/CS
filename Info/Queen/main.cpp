#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

#define nmax (int)1e5+10

vector <int> v[nmax];
vector <int> ans;
int cnt[nmax];
int nr[nmax];
int used[nmax];
int c[nmax];
int n,i,root;

void df(int x)
{
    if(c[x])
        cnt[x]++;
    nr[x]++;
    for(auto it:v[x])
    {
        if(!used[it])
            df(it);
        nr[x]+=1;
        cnt[x]+=(c[it]==1);
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    for(i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        if(x!=-1)
            v[x].pb(i);
        else
            root=i;
        cin>>c[i];
    }
    df(root);
    for(i=1; i<=n; ++i)
        if(nr[i]==cnt[i])
        {
            ans.pb(i);
        }
    for(auto it:ans)
        cout<<it<<' ';
    if(ans.size()==0)
        cout<<"-1";
}
