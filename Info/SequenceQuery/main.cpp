#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sequencequery.in");
ofstream fout("sequencequery.out");

#define ll long long
#define nmax 3200000

ll sum[nmax];
ll dr[nmax];
ll st[nmax];
ll ans[nmax];
int n,m,i,x,a,b;

struct nod
{
    ll sum,dr,st,ans;
};

void update(int p,int s,int d,int poz,int x)
{
    int m = (s+d)/2;
    if(s==d && s==poz)
    {
        sum[p]=st[p]=dr[p]=ans[p]=x;
        return ;
    }
    else
    if(poz>m)
        update(p*2+1,m+1,d,poz,x);
    else
        update(p*2,s,m,poz,x);

    sum[p]=sum[p*2] + sum[p*2+1];
    st[p]=max(st[p*2],sum[p*2]+st[p*2+1]);
    dr[p]=max(dr[p*2+1],sum[p*2+1]+dr[p*2]);
    ans[p]=max(ans[p*2],max(ans[p*2+1],max(st[p],max(dr[p],st[p*2+1]+dr[p*2]))));
}

nod query(int p,int s,int d,int a,int b)
{
    int m = (s+d)/2;
    if(s==a && d==b)
    {
        nod z;
        z.ans=ans[p];
        z.st=st[p];
        z.dr=dr[p];
        z.sum=sum[p];
        return z;
    }
    if(a>m)
        return query(p*2+1,m+1,d,a,b);
    if(b<=m)
        return query(p*2,s,m,a,b);
    else
    {
        nod z;
        nod x = query(p*2,s,m,a,m);
        nod y = query(p*2+1,m+1,d,m+1,b);

        z.sum=x.sum+y.sum;
        z.st=max(x.st,x.sum+y.st);
        z.dr=max(y.dr,y.sum+x.dr);
        z.ans=max(x.ans,max(y.ans,max(z.st,max(z.dr,x.dr+y.st))));
        return z;
    }
}

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        fin>>x;
        update(1,1,n,i,x);
    }
    while(m--)
    {
        fin>>a>>b;
        nod z = query(1,1,n,a,b);
        fout<<z.ans<<'\n';
    }
}
