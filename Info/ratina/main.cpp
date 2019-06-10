#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream fin("ratina.in");
ofstream fout("ratina.out");

#define nmax (int)2e5+10

string v[(int)1e4+10];
int poz[(int)1e4+10];
int lev[nmax*2];
int eu[nmax*2];
int rmq[18][nmax*2];

struct vertex
{
    vector <int> x;
    vertex *v[26];
    vertex()
    {
        for(int i=0; i<26; ++i)
            this->v[i]=NULL;
    }
};

vertex *root;

void add(vertex *&root,int curr,int x)
{
    if(x<v[curr].length())
    {
        if(root->v[v[curr][x]-'a']==NULL)
        {
            vertex *q = new vertex;
            root->v[v[curr][x]-'a']=q;
            add(q,curr,x+1);
        }
        else
        add(root->v[v[curr][x]-'a'],curr,x+1);
    }
    else
    root->x.push_back(curr);
}

int cnt = 0;

void euler(vertex *&root,int curr)
{
    eu[++cnt]=curr;
    for(auto it:root->x)
        poz[it]=cnt;
    for(int i=0; i<26; ++i)
        if(root->v[i]!=NULL)
        {
            euler(root->v[i],curr+1);
            eu[++cnt]=curr;
        }
}

inline int compute_log2(int x)
{
    int cnt = 1,ans = 1;
    while((ans<<1) <= x)
        ans<<=1,++cnt;
    return cnt;
}

inline int minim(int x,int y)
{
    if(x<y)
        return x;
    return y;
}

inline int maxim(int x,int y)
{
    if(x>y)
        return x;
    return y;
}

int main()
{
    root = new vertex;
    int n,q,i,j,x,a,b;
    fin>>n>>q;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
        add(root,i,0);
    }
    euler(root,0);
    n = cnt;
    int k = compute_log2(n);
    for(i=1; i<=n; ++i)
        rmq[1][i]=eu[i];
    for(i=2; i<=k; ++i)
        for(j=1; j<=n; ++j)
            rmq[i][j] = minim(rmq[i-1][j],rmq[i-1][j+(1<<(i-2))]);
    while(q--)
    {
        fin>>n;
        fin>>x;
        a = b = poz[x];
        for(i=2; i<=n; ++i)
        {
            fin>>x;
            a=minim(poz[x],a);
            b=maxim(poz[x],b);
        }
        k = compute_log2(b-a);
        fout<<minim(rmq[k][a],rmq[k][b-(1<<(k-1))+1])<<'\n';
    }
}
