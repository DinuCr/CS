#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("domino.in");
ofstream fout("domino.out");

struct date
{
    int f,s,nr;
};

int poz1[51000];
int poz2[51000];
vector <date> v[10];
int ans1[51000];
int ans2[51000];
date st[51000];
int z,m,k;
int viz[10];

void df(int x)
{
    viz[x]=1;
    for(int i=0; i<v[x].size(); ++i)
        if(viz[v[x][i].f]==0)
            df(v[x][i].f);
}

void euler()
{
    while(k!=0)
    {
        if(v[st[k].f].size())
        {

            st[k+1]=v[st[k].f][v[st[k].f].size()-1];
            v[st[k].f].pop_back();

            if(st[k+1].s==1)
            {
                if(v[st[k+1].f][v[st[k+1].f].size()-1].s==0)
                    poz1[v[st[k+1].f][v[st[k+1].f].size()-1].nr]=poz1[st[k+1].nr];
                else
                    poz2[v[st[k+1].f][v[st[k+1].f].size()-1].nr]=poz1[st[k+1].nr];
                swap(v[st[k+1].f][poz1[st[k+1].nr]],v[st[k+1].f][v[st[k+1].f].size()-1]);
                v[st[k+1].f].pop_back();
            }
            else
            {
                if(v[st[k+1].f][v[st[k+1].f].size()-1].s==0)
                    poz1[v[st[k+1].f][v[st[k+1].f].size()-1].nr]=poz2[st[k+1].nr];
                else
                    poz2[v[st[k+1].f][v[st[k+1].f].size()-1].nr]=poz2[st[k+1].nr];
                swap(v[st[k+1].f][poz2[st[k+1].nr]],v[st[k+1].f][v[st[k+1].f].size()-1]);
                v[st[k+1].f].pop_back();
            }
            ++k;
        }
        else
        {
            ++z;
            ans1[z]=st[k].nr;
            ans2[z]=st[k].s;
            --k;
        }
    }
}

int main()
{
    fin>>m;
    date x;
    int a,b,i;
    for(i=1; i<=m; ++i)
    {
        fin>>a>>b;
        x.f=b;
        x.s=0;
        x.nr=i;
        poz1[i]=v[a].size();
        v[a].push_back(x);
        x.f=a;
        x.s=1;
        poz2[i]=v[b].size();
        v[b].push_back(x);
    }
    int n=10;
    int nr=0;
    int prim=-1,ultim;
    for(i=0; i<n; ++i)
    {
        if(v[i].size()%2==1)
        {
            if(prim==-1)
                prim=i;
            else
                ultim=i;
            ++nr;
        }
        else if(v[i].size()>0 && prim==-1)
            prim=i;
    }
    int ok=1;
    df(prim);
    for(i=0; i<n; ++i)
        if(viz[i]==0 && v[i].size()>0)
            ok=0;


    if((nr!=0 && nr!=2) || ok==0)
        fout<<'0';
    else
    {
        k=1;
        st[k].f=prim;

        if(nr==2)
        {
            date x;
            x.f=ultim;
            x.nr=m+1;
            poz1[m+1]=v[prim].size();
            v[prim].push_back(x);
            x.f=prim;
            poz2[m+1]=v[ultim].size();
            v[ultim].push_back(x);
        }

        euler();
        fout<<1<<'\n';
        if(nr==2)
            --z;
        for(i=z-1; i>0; --i)
            fout<<ans1[i]<<' '<<ans2[i]<<'\n';
    }
}
