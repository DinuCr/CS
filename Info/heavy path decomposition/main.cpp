#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("heavypath.in");
ofstream fout("heavypath.out");

#define nmax 100010

vector <int> v[nmax];
vector <int> curr[nmax];
int poz[nmax];
int lev[nmax];
int lant[nmax];
int father[nmax];
int pathf[nmax];
int val[nmax];
int under[nmax];
int used[nmax];
int aint[nmax*2];
int path_nr,n,m;

#define DIM 10000
char buff[DIM];
int poz1=0;

void citeste(int &numar)
{
     numar = 0;
     while (buff[poz1] < '0' || buff[poz1] > '9')
          if (++poz1 == DIM)
               fin.read(buff,DIM),poz1=0;
     while ('0'<=buff[poz1] && buff[poz1]<='9')
     {
          numar = numar*10 + buff[poz1] - '0';
          if (++poz1 == DIM)
               fin.read(buff,DIM),poz1=0;
     }
}

void df(int x)
{
    used[x]=1;
    under[x]=1;
    int ok = 1;
    int mx = 0;
    int path = 0;
    for(auto it:v[x])
        if(!used[it])
        {
            ok=0;
            father[it]=x;
            lev[it]=lev[x]+1;
            df(it);
            under[x]+=under[it];
            if(under[it]>mx)
                mx=under[it],path=lant[it];
        }

    if(ok)
    {
        curr[path_nr].push_back(x);
        lant[x]=path_nr++;
        return ;
    }
    lant[x]=path;
    curr[path].push_back(x);
}

void build_paths()
{
    int ct = 0;
    for(int i=0; i<path_nr; ++i)
    {
        for(auto it:curr[i])
        {
            aint[ct+n]=val[it];
            poz[it]=ct+n;
            pathf[it]=curr[i].back();
            ++ct;
        }
    }
}

void build_segment_tree()
{
    for(int i=n-1; i; --i)
        aint[i]=max(aint[i<<1],aint[i<<1|1]);
}

void update(int a,int b)
{
    aint[poz[a]]=b;
    for(int i=poz[a]>>1 ; i; i>>=1)
        aint[i]=max(aint[i<<1],aint[i<<1|1]);
}

int query(int a,int b)
{
    int ans = 0;
    for( ; a<b; a>>=1,b>>=1)
    {
        if(a&1)
            ans=max(ans,aint[a++]);
        if(b&1)
            ans=max(ans,aint[--b]);
    }
    return ans;
}

int compute(int a,int b)
{
    int ans = 0;
    while(1)
    {
        if(lant[a]==lant[b])
        {
            return max(ans,query(min(poz[a],poz[b]),1+max(poz[a],poz[b])));
        }
        if(lev[pathf[a]]<lev[pathf[b]])
            swap(a,b);
        ans = max(ans,query(poz[a],poz[pathf[a]]+1));
        a = father[pathf[a]];
    }
    return ans;
}

int main()
{
    int p,i,a,b;
    citeste(n);
    citeste(m);
    for(i=1; i<=n; ++i)
        citeste(val[i]);
    for(i=1; i<n; ++i)
    {
        citeste(a);
        citeste(b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    lev[1]=1;
    df(1);
    build_paths();
    build_segment_tree();
    while(m--)
    {
        citeste(p);
        citeste(a);
        citeste(b);
        if(p==0)
            update(a,b);
        else
            fout<<compute(a,b)<<'\n';
    }
}
