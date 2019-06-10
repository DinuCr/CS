#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

ifstream fin("immortal.in");
ofstream fout("immortal.out");

#define mp make_pair
#define f first
#define s second

struct rasp
{
    int a,b,c,d;
};

set <pair<int,int> > h;
int v[23][23];
rasp ans[100];
int n,m,k;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void bkt()
{
    int i;

    if(h.size()==1)
    {
        for(i=0; i<k; ++i)
            fout<<ans[i].a<<' '<<ans[i].b<<' '<<ans[i].c<<' '<<ans[i].d<<'\n';
        exit(0);
    }

    rasp pos[60];
    int z = 0;
    for(auto it:h)
    {
        for(int i=0; i<4; ++i)
            if(v[it.f+dx[i]][it.s+dy[i]] && it.f+2*dx[i]<=n && it.f+2*dx[i]>0 && it.s+2*dy[i]>0 && it.s+2*dy[i]<=m && !v[it.f+2*dx[i]][it.s+2*dy[i]])
            {
                pos[z].a=it.f;
                pos[z].b=it.s;
                pos[z].c=dx[i];
                pos[z++].d=dy[i];
            }
    }
    rasp it;
    for(i=0; i<z; ++i)
    {
        it = pos[i];
        v[it.a][it.b]=0;
        v[it.a+it.c][it.b+it.d]=0;
        v[it.a+2*it.c][it.b+2*it.d]=1;
        ans[k].a=it.a;
        ans[k].b=it.b;
        ans[k].c=it.a+2*it.c;
        ans[k++].d=it.b+2*it.d;
        h.erase(mp(it.a,it.b));
        h.erase(mp(it.a+it.c,it.b+it.d));
        h.insert(mp(it.a+2*it.c,it.b+2*it.d));

        bkt();

        h.insert(mp(it.a,it.b));
        h.insert(mp(it.a+it.c,it.b+it.d));
        h.erase(mp(it.a+2*it.c,it.b+2*it.d));
        v[it.a][it.b]=1;
        v[it.a+it.c][it.b+it.d]=1;
        v[it.a+2*it.c][it.b+2*it.d]=0;
        --k;
    }
}

int main()
{
    int a,b;
    fin>>n>>m>>k;
    for(int i=1; i<=k; ++i)
    {
        fin>>a>>b;
        v[a][b]=1;
        h.insert(mp(a,b));
    }
    k=0;
    bkt();
}
