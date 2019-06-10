#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("biscuiti.in");
ofstream fout("biscuiti.out");

#define ll long long
#define nmax 100100

const ll inf = 1000000000000;

struct nod
{
    ll mn,poz,add;
};

nod aint[nmax*17];
ll n,i,x,ans,poz,sum;

void update(int p,int ls,int ld,int a,int b,ll val)
{
    if(a<=ls && ld<=b)
    {
        aint[p].mn+=val;
        aint[p].add+=val;
        if(a==b)
        {
            aint[p].poz=a;
        }
    }
    else
    {
        int m = (ls+ld)>>1;
        if(a<=m)
            update(p<<1,ls,m,a,b,val);
        if(b>m)
            update(p<<1|1,m+1,ld,a,b,val);
        if(aint[p<<1].mn<=aint[p<<1|1].mn)
        {
            aint[p].mn=aint[p<<1].mn+aint[p].add;
            aint[p].poz=aint[p<<1].poz;
        }
        else
        {
            aint[p].mn=aint[p<<1|1].mn+aint[p].add;
            aint[p].poz=aint[p<<1|1].poz;
        }
    }
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>x;
        sum+=x;
        update(1,1,n,i,i,x);
    }
    for(i=1; i<=n; ++i)
    {
        ans += aint[1].mn;
        poz = aint[1].poz;
        update(1,1,n,poz,poz,inf);
        update(1,1,n,1,poz,i);
    }
    fout<<ans-sum;
}
