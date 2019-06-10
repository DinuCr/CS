#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("pscnv.in");
ofstream fout("pscnv.out");

#define nmax 250001
#define mp make_pair
#define f first
#define s second

const int inf = 1e9;


#define DIM 10000
char buff[DIM];
int poz=0;

void citeste(int &numar)
{
     numar = 0;
     //cat timp caracterul din buffer nu e cifra ignor
     while (buff[poz] < '0' || buff[poz] > '9')
          //daca am "golit" bufferul atunci il umplu
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     //cat timp dau de o cifra recalculez numarul
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     }
}


priority_queue <pair<int,int> , vector <pair<int,int> >, greater <pair<int,int> > >h;
vector <pair<int,int> > v[nmax];
int ans[nmax];
int n,m,i,a,b,x,y,cost;

int main()
{
    freopen("pscnv.in","r",stdin);
    freopen("pscnv.out","w",stdout);
    citeste(n);
    citeste(m);
    citeste(a);
    citeste(b);
    for(i=1; i<=m; ++i)
    {
        citeste(x);
        citeste(y);
        citeste(cost);
        v[x].push_back(mp(cost,y));
    }
    for(i=1; i<=n; ++i)
        ans[i]=inf;
    ans[a]=0;
    h.push(mp(0,a));
    while(h.size() && h.top().f<ans[b])
    {
        int nod = h.top().s;
        h.pop();
        for(i=0; i<v[nod].size(); ++i)
            if(max(v[nod][i].f,ans[nod])<ans[v[nod][i].s])
            {
                ans[v[nod][i].s]=max(v[nod][i].f,ans[nod]);
                h.push(mp(ans[v[nod][i].s],v[nod][i].s));
            }
    }
    cout<<ans[b];
}
