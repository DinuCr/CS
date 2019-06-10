#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("descompune.in");
ofstream fout("descompune.out");

#define nmax 10010
#define mp make_pair
#define f first
#define s second

vector <pair<int,int> > curr;
char sir[nmax];
char p[55];
pair<int,int> v[nmax];
char d[nmax*10][55];
int len[nmax*10];
int cost[nmax*10];
int n,q,m,i,ok,j;

int main()
{
    fin>>sir;
    n = strlen(sir);
    fin>>q;
    for(int k=1; k<=q; ++k)
    {
        fin>>p>>cost[k];
        strcpy(d[k],p);
        m = strlen(p);
        len[k]=m;

        int lim = n-m;
        for(i=0; i<=lim; ++i)
        {
            ok=1;
            for(j=0; j<m; ++j)
                if(sir[i+j]!=p[j])
                {
                    ok=0;
                    break;
                }
            if(ok)
                curr.push_back(mp(i-1,k));
        }
    }
    sort(curr.begin(),curr.end());
    for(auto it:curr)
        if(it.f==-1)
        {
            if(v[it.f+len[it.s]].f>cost[it.s] || v[it.f+len[it.s]].f==0)
            {
                v[it.f+len[it.s]].f=cost[it.s];
                v[it.f+len[it.s]].s=it.s;
            }
        }
        else
        if(v[it.f].f!=0)
        {
            if(v[it.f+len[it.s]].f>cost[it.s]+v[it.f].f || v[it.f+len[it.s]].f==0)
            {
                v[it.f+len[it.s]].f=cost[it.s]+v[it.f].f;
                v[it.f+len[it.s]].s=it.s;
            }
        }
    vector <int> ans;
    for(i=n-1; i>=0; i-=len[v[i].s])
        ans.push_back(v[i].s);
    fout<<v[n-1].f;
}
