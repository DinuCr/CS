#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int n,m,i,j;
int v[2000010];
int d[2000010];
int used[2000010];

pair<int,int> q[2000010];
int k;

int lo(int a,int b)
{
    return (a-1)*m+b;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n>>m;

    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
        {
            char c;
            cin>>c;
            if(c=='.')
                v[lo(i,j)]=0;
            else
                v[lo(i,j)]=1e9;
        }
    }

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(v[lo(i,j)]!=1e9)
            {
                if(i>1 && j>1)
                v[lo(i,j)]=min(v[lo(i-1,j)],v[lo(i,j-1)])+1;

                else
                if(i>1)
                v[lo(i,j)]=v[lo(i-1,j)]+1;

                else
                if(j>1)
                v[lo(i,j)]=v[lo(i,j-1)]+1;

                v[lo(i,j)]=min((int)1e9,v[lo(i,j)]);


            }

    q[0]=mp(n,m);
    k=0;
    int lim = 0;
    while(k<=lim)
    {
        int x = q[k].f;
        int y = q[k].s;
        k++;
        if(v[lo(x,y)]>=1e9)
            continue;
        d[v[lo(x,y)]]++;

        if(x>1 && v[lo(x,y)]==1+v[lo(x-1,y)] && !used[lo(x-1,y)])
            q[++lim]=(mp(x-1,y)),used[lo(x-1,y)]=1;

        if(y>1 && v[lo(x,y)]==1+v[lo(x,y-1)] && !used[lo(x,y-1)])
            q[++lim]=(mp(x,y-1)),used[lo(x,y-1)]=1;
    }
    int ans = 1e9;
    for(i=1; i<m+n-2; ++i)
        ans=min(ans,d[i]);

    cout<<ans;
}
