#include <cstdio>
#include <cmath>
#include <bitset>
using namespace std;

FILE *f=fopen("ssnd.in","r");
FILE *g=fopen("ssnd.out","w");
#define ll long long
#define fs(n) fscanf(f,"%lld",&n)
#define fp fprintf
#define m(x) x%9973
inline ll po(ll a,ll b)
{
    if(b==1)
        return m(a);
    else
    if(b%2==0)
        return m(po((a*a),b/2));
    return m(a*po(a,b-1));
}
struct nod
{
    int f,p;
}v[100];
#define nmax 1000010

bool p[nmax/2+1];
int prim[nmax/4];
int i,j,m,z;
unsigned long long x,s,nr,n,mx;

int main()
{
    prim[0]=2;x=nmax;
    for(i=1; (((i*i)<<1)+(i<<1))<=x; ++i)
    {
        if(!p[i])
        {
            for(j=(((i*i)<<1)+(i<<1)) ; (j<<1) <=x; j+= (i<<1) +1 )
                p[j]=1;
        }
    }
    m=1;
    for(i=1; (i<<1)+1<nmax; ++i)
        if(!p[i])
            prim[m++]=(i<<1)+1;
    fs(n);
    for(i=1;i<=n;i++)
    {
        fs(x);
        z=0;
        mx=sqrt(x)+1;
        for( j=0; j<m && prim[j]<mx; ++j)
        if(x%prim[j]==0)
        {
            v[z].f=prim[j];
            v[z++].p=1;
            x/=prim[j];
            while(x%prim[j]==0)
            {
                v[z-1].p++;
                x/=prim[j];
            }
            if(x==1)
                break;
        }
        if(x!=1)
            {
                v[z].f=x;
                v[z++].p=1;
            }
        nr=1;
        s=1;
        for( j=0; j<z; ++j)
        {
            nr*=v[j].p+1;
            s*=(m(po(v[j].f,v[j].p+1)-1))/m(v[j].f-1);
            s%=9973;
        }
        fp(g,"%lld %lld\n",nr,s);
    }
}/*
#include <fstream>
#include <bitset>

using namespace std;

const int MAX_N = 1000005;
const int MOD = 9973;

ifstream fin ("ssnd.in");
ofstream fout ("ssnd.out");

long long N;
int T, K, P[MAX_N];
bitset <MAX_N> viz;

void ciur() {
    for(int i = 2; i < MAX_N; ++i) {
        if(viz[i] == 0) {
            P[++K] = i;

            for(int j = i+i; j < MAX_N; j += i) {
                viz[j] = 1;
            }
        }
    }
}

inline int pow(int x, int p) {
    int rez = 1;
    x %= MOD;

    for(; p; p >>= 1) {
        if(p & 1) {
            rez *= x;
            rez %= MOD;
        }

        x *= x;
        x %= MOD;
    }

    return rez;
}

void solve() {
    fin >> N;

    int nd = 1, sd = 1;

    for(int i = 1; i <= K && 1LL * P[i] * P[i] <= N; ++i) {
        if(N % P[i]) continue;
        int p = 0;

        while(N % P[i] == 0) {
            N /= P[i];
            ++p;
        }

        nd *= (p+1);

        int p1 = (pow(P[i], p+1) - 1) % MOD;
        int p2 = pow(P[i]-1, MOD-2) % MOD;

        sd = (((sd * p1) % MOD) * p2) % MOD;
    }

    if(N > 1) {
        nd *= 2;
        sd = (1LL*sd*(N+1) % MOD);
    }

    fout << nd << " " << sd << "\n";
}

int main() {
    ciur();

    for(fin >> T; T; --T)
        solve();
}*/
