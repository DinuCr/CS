#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define nmax (int) 63400

ifstream fin("suma4.in");
ofstream fout("suma4.out");

vector <int> w[nmax];
vector <int> v[nmax];
short value[nmax];
short d[nmax];
int i,n,j;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int curr,scurr;

    fin>>n;
    for(i=1; i<=n+1; ++i)
        fin>>value[i],d[i]=1e9;
    d[1]=0;
    for(scurr = 0, curr = 1; scurr<n; ++curr)
    {
        int curr2 = curr*curr;
        for(i=1; i<=curr; ++i)
            for(j=1; j<=curr; ++j)
            {
                if(scurr+curr2<n)
                {
                    v[scurr+(i-1)*curr+j].pb(scurr+curr2+(i-1)*(curr+1)+j+1);
                    v[scurr+(i-1)*curr+j].pb(scurr+curr2+i*(curr+1)+j);
                    v[scurr+(i-1)*curr+j].pb(scurr+curr2+i*(curr+1)+j+1);
                    v[scurr+(i-1)*curr+j].pb(scurr+curr2+(i-1)*(curr+1)+j);

                    v[scurr+curr2+(i-1)*(curr+1)+j+1].pb(scurr+(i-1)*curr+j);
                    v[scurr+curr2+i*(curr+1)+j].pb(scurr+(i-1)*curr+j);
                    v[scurr+curr2+i*(curr+1)+j+1].pb(scurr+(i-1)*curr+j);
                    v[scurr+curr2+(i-1)*(curr+1)+j].pb(scurr+(i-1)*curr+j);
                }
                else
                    v[scurr+(i-1)*curr+j].pb(n+1),v[n+1].pb(scurr+(i-1)*curr+j);
            }
        scurr+=curr2;
    }
    fout<<curr-1<<' ';
    priority_queue <pair<short,int>, vector <pair<short,int> >,greater<pair<short,int> > > q;
    q.push(mp(0,1));
    while(!q.empty())
    {
        int node = q.top().s;
        int x = q.top().f;
        q.pop();
        if(x!=d[node])
            continue;
        for(auto it:v[node])
            if(it>node)
                if(d[node]+value[node]<d[it])
                    d[it]=d[node]+value[node],q.push(mp(d[it],it));
    }
    fout<<d[n+1]<<'\n';
    queue <int> h;
    h.push(n+1);
    while(!h.empty())
    {
        int node = h.front();
        h.pop();
        for(auto it:v[node])
            if(it<node)
                if(d[node]==value[it]+d[it])
                    w[it].pb(node),h.push(it);
    }
    curr = 1;
    while(curr!=n+1)
    {
        fout<<curr<<' ';
        int nxt = 1e9;
        for(auto it:w[curr])
            nxt=min(nxt,it);
        curr = nxt;
    }
}
