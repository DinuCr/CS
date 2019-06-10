#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("spiridusi.in");
ofstream fout("spiridusi.out");

#define nmax 100010

vector <int> v[nmax];
int rmq[nmax][18];
int ans[nmax][18];
int cst[nmax];
int scst[nmax];
int sp[nmax];
int p[nmax],c,rez;

void df(int x,int t)
{
    rmq[x][0]=t;
    scst[x]=scst[t]+cst[x];
    sp[x]=sp[t]+p[x];
    ans[x][0]=sp[t];
    int k=0;
    while(rmq[x][k]!=0)
    {
        ++k;
        rmq[x][k]=rmq[rmq[x][k-1]][k-1];
        ans[x][k]=min(ans[x][k-1],ans[rmq[x][k-1]][k-1]);
    }
    int curr = 1e9+100;
    int lim = k;

    int c2 = c;
    int nod = x;
    while(c2 && nod)
    {
        k = 0;
        while(k<=lim && scst[nod]-scst[rmq[nod][k]]<=c2)
            ++k;
        --k;
        if(k<0)
            break;
        else
        {
            curr = min(curr,ans[nod][k]);
            c2 -= scst[nod]-scst[rmq[nod][k]];
            nod = rmq[nod][k];
        }
    }
    rez = max(rez,sp[x]-curr);
    for(auto it:v[x])
        if(it!=t)
            df(it,x);
}

int main()
{
    int n,i;
    fin>>n>>c;
    for(i=1; i<=n; ++i)
        fin>>cst[i];
    for(i=1; i<=n; ++i)
        fin>>p[i];
    int a,b;
    for(i=1; i<n; ++i)
    {
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    rez = -1e9;
    df(1,0);
    fout<<rez;
}
