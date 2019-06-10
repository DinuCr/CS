#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

ifstream fin("arbore.in");
ofstream fout("arbore.out");

#define nmax 100100
#define Nmax 100100

vector <int> v[nmax];
vector <int> g[nmax];
int last[nmax];
int arbore[nmax];
int poz[nmax];
int viz[nmax];
int d[nmax];
int s,ans,rad,n,m,i,a,b,q,x,z,k,curr,nr,length;
bool sec[320][Nmax];
int cnt[320];

void df(int x)
{
    arbore[++k]=x;
    poz[x]=k;
    for(int i=0; i<v[x].size(); ++i)
        df(v[x][i]);
    last[poz[x]]=k;
}

void create(int x)
{
    viz[x]=1;
    for(int i=0; i<g[x].size(); ++i)
        if(!viz[g[x][i]])
        {
            viz[g[x][i]]=1;
            v[x].push_back(g[x][i]);
            create(g[x][i]);
        }
}

void update(int s,int dr,int x)
{
    int lft = (s-1) / length + 1;
    int rgt = (dr-1) / length + 1;

    for(int i=lft+1; i<rgt; ++i)
        cnt[i]+=x;
    int i;

    if(lft<rgt)
    {
        int a = (lft-1)*length;
        int b = (lft)*length;

        for(i=a+1; i<=b; ++i)
            sec[lft][d[i]]=0;
        for(i=s; i<=b; ++i)
            d[i]+=x;
        for(i=a+1; i<=b; ++i)
            sec[lft][d[i]]=1;

        a = (rgt-1)*length;
        b = (rgt)*length;

        for(i=a+1; i<=b; ++i)
            sec[rgt][d[i]]=0;
        for(i=a+1; i<=dr; ++i)
            d[i]+=x;
        for(i=a+1; i<=b; ++i)
            sec[rgt][d[i]]=1;
    }
    else
    {

        int a = (lft-1)*length;
        int b = (lft)*length;

        for(i=a+1; i<=b; ++i)
            sec[rgt][d[i]]=0;
        for(i=s; i<=dr; ++i)
            d[i]+=x;
        for(i=a+1; i<=b; ++i)
            sec[rgt][d[i]]=1;
    }
}

void query(int x)
{
    for(int i=1; i<=nr; ++i)
        if(sec[i][x-cnt[i]])
        {
            int k = min(i*length,n);
            for(int j=(i-1)*length+1; j<=k; ++j)
                if(cnt[i]+d[j]==x)
                {
                    ans=arbore[j];
                    return;
                }
        }
    return;
}

int main()
{
    fin>>n>>q;
    for(i=1; i<n; ++i)
    {
        fin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    k=0;
    create(1);
    df(1);

    length = sqrt(n);
    nr = n/length + (n-n/length*length>0);

    for(int i=1; i<=nr; ++i)
        sec[i][0]=1;

    while(q--)
    {
        fin>>x;
        switch(x)
        {
        case 1:
            fin>>z>>s;
            update(poz[z],last[poz[z]],s);
            break;
        case 2:
            fin>>s;
            ans=-1;
            query(s);
            fout<<ans<<'\n';
            break;
        }
    }
}
