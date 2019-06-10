#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("zmeu.in");
ofstream fout("zmeu.out");

#define pb push_back
#define mp make_pair
#define inf 10000
#define f first
#define s second

//priority_queue <pair<int,int>,vector <pair<int,int> >, greater<pair<int,int> > >q;
//vector <pair<int,int> >v[100];
int d[10][10];
int d0[10];
int curr[100];
int poz[10];
int ans = inf;
int bck[10];
int exit[100];
int viz[10],n,m,p,i;

/*void bkt(int k,int sum)
{
    if(k==6)
    {
        ans = min(ans,sum+d[bck[5]][6]);
    }
    else
    {
        for(int i=1; i<=5; ++i)
            if(!viz[i])
            {
                bck[k]=i;
                viz[i]=1;
                if(k==1)
                    bkt(k+1,sum+d0[i]);
                else
                    bkt(k+1,sum+d[bck[k-1]][i]);
                viz[i]=0;
            }
    }
}*/

int main()
{
    fin>>n>>m>>p;
    for(i=1; i<=6; ++i)
        fin>>poz[i];

    int x,y,cst;
    for(i=1; i<=m; ++i)
    {
        fin>>x>>y>>cst;
        //  v[x].pb(mp(y,cst));
        //  v[y].pb(mp(x,cst));
    }
    /*for(i=1; i<=p; ++i)
        fin>>exit[i];
    for(i=1; i<=n; ++i)
        curr[i]=inf;
    curr[poz[1]]=0;
    q.push(mp(0,poz[1]));
    while(!q.empty())
    {
        int nod = q.top().s;
        if(curr[nod]!=q.top().f)
        {
            q.pop();
            continue;
        }
        q.pop();
        for(int it=0; it<v[nod].size(); ++it)
        {
            if(curr[nod]+v[nod][it].s<curr[v[nod][it].f])
            {
                curr[v[nod][it].f]=v[nod][it].s+curr[nod];
                q.push(mp(curr[v[nod][it].f],v[nod][it].f));
            }
        }
    }
    for(i=1; i<=5; ++i)
        d[i][6]=inf;
    for(i=1; i<8; ++i)
        for(int j=1; j<8; ++j)
            d[i][j]=inf;
    for(i=1; i<=5; ++i)
        d0[i]=curr[poz[i+1]];
    for(i=1; i<=5; ++i)
    {
        for(int j=1; j<=n; ++j)
            curr[j]=inf;
        curr[poz[i+1]]=0;
        q.push(mp(0,poz[i+1]));
        while(!q.empty())
        {
            int nod = q.top().s;
            if(curr[nod]!=q.top().f)
            {
                q.pop();
                continue;
            }
            q.pop();
            for(int it=0; it<v[nod].size(); ++it)
            {
                if(curr[nod]+v[nod][it].s<curr[v[nod][it].f])
                {
                    curr[v[nod][it].f]=v[nod][it].s+curr[nod];
                    q.push(mp(curr[v[nod][it].f],v[nod][it].f));
                }
            }
        }
        for(int j=1; j<=5; ++j)
            if(i!=j)
                d[i][j]=min(d[i][j],curr[poz[j+1]]);
        for(int j=1; j<=p; ++j)
            d[i][6]=min(d[i][6],curr[exit[j]]);
    }
    //bkt(1,0);
    fout<<ans;*/
}
