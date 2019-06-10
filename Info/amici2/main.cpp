#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <cmath>
#include <queue>

using namespace std;

ifstream fin("amici2.in");
ofstream fout("amici2.out");

#define nmax 21010
#define mai_mic_sau_egal <=
#define creste ++
#define il_fac_1 =1
#define trec_la_rand_nou fout<<'\n'
#define inmultit_cu *
#define scade --
#define citesc(a) fin>>a;
#define numar int
#define nimic void
#define ia_maxim_dintre(a,b) max(a,b)
#define si ,
#define ia_valoarea =

vector <numar> v[nmax];
numar d[nmax];
numar mx;

nimic bf()
{
    queue <int> q;
    q.push(1);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        mx ia_valoarea ia_maxim_dintre(mx , d[x]);
        for(auto it:v[x])
            if(!d[it])
                q.push(it) si d[it] ia_valoarea d[x]+1;
    }
}

int main()
{
    numar t,n,m,i;
    citesc(t);
    while(t scade)
    {
        citesc(n);
        citesc(m);
        numar a,b;
        for(i il_fac_1; i mai_mic_sau_egal m; creste i)
        {
            fin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        d[1] il_fac_1;
        mx il_fac_1;
        bf();
        fout<<(int)log2(mx inmultit_cu 2);
        trec_la_rand_nou;
        for(i il_fac_1; i mai_mic_sau_egal n; creste i)
            v[i].clear();
        memset(d, 0, sizeof(d));
    }
}
