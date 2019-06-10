#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ifstream fin("arborest.in");
ofstream fout("arborest.out");

#define nmax (int) 1e5+10

vector <int> v[nmax];
int t[nmax];
int d[nmax];
int ord[nmax];
int used[nmax];
int n,k;

void df(int x)
{
    for(auto it:v[x])
        d[it]=d[x]+1,df(it);
}

inline bool cmp(int a,int b)
{
    return d[a]>d[b];
}

void mark(int x)
{
    used[x]=1;
    for(auto it:v[x])
        if(!used[it])
            mark(it);
}

bool check(int q)
{
    int curr = 0,i;
    memset(used, 0, sizeof(used));
    for(i=1; i<=n && d[ord[i]]>q; ++i)
        if(!used[ord[i]] && d[ord[i]]>q)
        {
            int nth = 0;
            int x = ord[i];
            while(nth<q-1)
                x=t[x],++nth;
            mark(x);
            ++curr;
            if(curr>k)
                return 0;
        }
    return 1;
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int i;

    fin>>n>>k;
    for(i=2; i<=n; ++i)
    {
        fin>>t[i];
        v[t[i]].pb(i);
    }
    d[1]=0;
    df(1);
    for(i=1; i<=n; ++i)
        ord[i]=i;
    sort(ord+1,ord+n+1,cmp);
    int ans = n;
    for(i=1; i<=n; i<<=1);
    for( ; i; i>>=1)
        if(ans-i>=2 && check(ans-i))
            ans-=i;
    fout<<ans;
}

