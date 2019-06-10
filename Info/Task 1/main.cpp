#include<cstdio>
#include<algorithm>
#include<cstring>
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define ll long long

const int NMAX = 1e5+5;

int ax[] = {1, 0, -1, 0}, ay[] = {0, 1, 0, -1};

int wx,wy;

inline bool isGood(int x,int y)
{
    return (x >= 0 && x < wx) && (y >= 0 && y < wy);
}

#define nmax (int)(1e6)+10

vector <int> spawn;
vector <pair<int,int> >v;
vector <pair<int,int> >towerpos;
int sp[nmax];
double dist[nmax];
double hp[nmax];
int locked[nmax];
int dead[nmax];
bool used[1001][1001];
int luat [nmax];

ll distance(int a,int b, int c, int d)
{
    return 1LL*(a-c)*(a-c)+1LL*(b-d)*(b-d);
}

bool compare(pair<int,pair<int,int> > &a, pair<int,pair<int,int> > &b)
{
    return a.f>b.f;
}

int main()
{
    freopen("level5_4.in","r",stdin);
    freopen("output4.txt","w",stdout);

    int x,y,i,j = 0;
    scanf("%d%d\n",&wx,&wy);
    scanf("%d%d\n\n",&x,&y);
    char ch;
    v.pb(mp(x,y));
    used[x][y]=1;
    while(scanf("%c",&ch) != EOF)
    {
        int dif;
        scanf("%d",&dif);
        if(ch == 'F')
        {
            bool ok = 1;
            for(i = 1 ; ok && i <= dif ; ++i)
            {

                if(isGood(x+ax[j],y+ay[j]))
                {
                    x += ax[j];
                    y += ay[j];
                    v.pb(mp(x,y));
                    used[x][y]=1;
                }
                else
                    ok = 0;
            }
        }
        else
        {
            j = (j+dif)%4;
        }
        scanf("%c",&ch);
        if(ch=='\n')
        {
            x += ax[j];
            y += ay[j];
            if(x>=0 && y>=0)
            used[x][y]=1;
            break;
        }
    }

    double speed,health;
    int nr;
    scanf("%lf%lf",&health,&speed);
    scanf("%d",&nr);
    for(int i=0; i<nr; ++i)
    {
        int abc;
        scanf("%d",&abc);
        spawn.pb(abc);
    }
    double damage;
    ll range;
    ll cost;
    ll gold;
    scanf("%lf%lld%lld%lld",&damage,&range,&cost,&gold);
    range = range*range;

    vector <pair<int,pair<int,int> > > h;
    int nrmax = min(500LL,gold/cost);
    for(i=0; i<wx; ++i)
        for(j=0; j<wy; ++j)
        if(used[i][j]==0)
        {
            int curr = 0;
            for(auto it:v)
            {
                if(distance(i,j,it.f,it.f)<=range)
                    curr++;
            }
            h.pb(mp(curr,mp(i,j)));
        }
    vector <pair<int,int> > ans;
    srand(time(NULL));
    sort(h.begin(),h.end(),compare);
    i=0;
    int lasta, lastb;
    int k = 14;
    while(nrmax)
    {
        ll dis = range;
        for(auto it:ans)
        {
            dis=min(dis,distance(it.f,it.s,h[i].s.f,h[i].s.s));
        }
        if(rand()%2>0 && luat[i]==0 && (dis>=range/k))
            luat[i]=1,ans.pb(mp(h[i].s.f,h[i].s.s)),nrmax--,lasta=h[i].s.f,lastb=h[i].s.s;
        i++;
        if(i==h.size())
            i=0,k++;
    }
    for(auto it:ans)
    {
        printf("%d %d\n",it.f,it.s);
    }
    /*range = 1LL*range*range;
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        towerpos.pb(mp(a,b));
        locked[q]=-1;
    }
    int timp = 0;
    while(1)
    {
        for(i=0; i<nr; ++i)
            if(sp[i]==1 && hp[i]>0)
            {
                dist[i]+=speed;
                if(floor(dist[i])==v.size())
                {
                    printf("%d\nLOSS",timp);
                    return 0;
                }
            }
        for(i=0; i<nr; ++i)
        {
            if(spawn[i]==timp)
                timp,sp[i]=1,hp[i]=health;
        }
        for(i=0; i<nr; ++i)
            if(hp[i]>0)
                dead[i]=0;
            else
                dead[i]=1;
        if(timp>0)
        for(i=0; i<towerpos.size(); ++i)
        {
            int a = towerpos[i].f;
            int b = towerpos[i].s;
            if(locked[i]>=0)
            {
                if(dead[locked[i]]==0 && distance(v[dist[locked[i]]].f,v[dist[locked[i]]].s,a,b)<=range)
                    hp[locked[i]]-=damage;
                else
                {
                    ll mn = range+1;
                    int ans = -1;
                    for(int j=0; j<nr; ++j)
                        if(hp[j]>0 && distance(v[dist[j]].f,v[dist[j]].s,a,b)<mn)
                            mn = distance(v[dist[j]].f,v[dist[j]].s,a,b),ans = j;
                    if(mn<=range && ans!=-1)
                        hp[ans]-=damage,locked[i]=ans;
                }
            }
            else
            {
                ll mn = range+1;
                int ans = -1;
                for(int j=0; j<nr; ++j)
                    if(dead[j]==0 && distance(v[dist[j]].f,v[dist[j]].s,a,b)<mn)
                        mn = distance(v[dist[j]].f,v[dist[j]].s,a,b),ans = j;
                if(mn<=range && ans!=-1)
                    hp[ans]-=damage,locked[i]=ans;
            }
        }
        int ok = 0;
        for(i=0; i<nr; ++i)
            if(sp[i]!=1 || hp[i]>0)
                ok=1;

        if(ok==0)
        {
            printf("%d\nWIN",timp);
            return 0;
        }
        timp++;
    }*/

}
