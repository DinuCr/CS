#include <stack>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("zlego.in");
ofstream fout("zlego.out");

#define nmax 300110
#define ll long long
#define f first
#define s second
#define mp make_pair

vector <int> v[nmax];
ll d[nmax];
int phi[nmax];
int w[nmax];
int n,i;

void compute_phi()
{
    int k;
    v[0].push_back(1);
    for(int i=2; i<=n; ++i)
    {
        k=phi[i-1];
        while(k && w[i]!=w[k+1])
            k=phi[k];
        if(w[i]==w[k+1])
            phi[i]=k+1;
        else
        phi[i]=0;
        v[phi[i]].push_back(i);
    }
}

void solve()
{
    for(int i=n; i>0; --i)
        d[phi[i]]+=d[i];
}

int main()
{
    int t;
    fin>>t;
    while(t--)
    {
        fin>>n;
        for(i=1; i<=n; ++i)
            fin>>w[i];
        for(i=1; i<=n; ++i)
            fin>>d[i];
        compute_phi();
        solve();
        for(i=1; i<=n; ++i)
            fout<<d[i]<<'\n';
    }
}
