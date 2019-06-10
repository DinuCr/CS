#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define nmax 100010
#define mp make_pair
#define f first
#define s second

vector <int> v[nmax];
int viz[nmax];
int n,k,ans;
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
void bf()
{
    queue <pair<int,pair<int,int> > >q;
    int i;
    for(i=1; i<=n; ++i)
    {
        if(v[i].size()==1)
        {
            q.push(mp(i,mp(0,i)));
            viz[i]=1;
        }
    }
    int nod,l,f;
    while(!q.empty())
    {
        nod = q.front().f;
        l = q.front().s.f;
        f = q.front().s.s;
        q.pop();
        if(l==k)
            continue;
        for(auto it:v[nod])
            if(viz[it]<2 && it!=f)
            {
                ++viz[it];
                q.push(mp(it,mp(l+1,nod)));
            }
    }
}

int main()
{
    freopen("statiuni.in","r",stdin);
    freopen("statiuni.out","w",stdout);
    citeste(n);
    citeste(k);
    int x,y;
    for(int i=1; i<n; ++i)
    {
        citeste(x);
        citeste(y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bf();
    for(int i=1; i<=n; ++i)
        if(viz[i]==2)
            ++ans;
    printf("%d",ans);
}
