#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define nmax (int)1e3+10

ifstream fin("zoro.in");
ofstream fout("zoro.out");

pair<int,int> pos[(nmax)*(nmax)];
int d[(nmax)*(nmax)];
int dl[nmax];
int dc[nmax];

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int i,j,n,m,start,stop;

    fin>>n>>m;
    fin>>start;
    pos[start]=mp(1,1);
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        if(i+j>2)
        {
            int x;
            fin>>x;
            pos[x]=mp(i,j);
            stop = x;
        }
    d[start]=dc[1]=dl[1]=1;
    for(i=start-1; i>=stop; --i)
    {
        d[i]=max(dl[pos[i].f],dc[pos[i].s])+1;
        dl[pos[i].f]=dc[pos[i].s]=d[i];
    }
    fout<<d[stop];
}
