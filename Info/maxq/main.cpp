#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("maxq.in");
ofstream fout("maxq.out");

#define nmax 3200100
#define ll long long

struct nod
{
    ll ans,lft,rgt,sum;
};

ll ans[nmax];
ll lft[nmax];
ll rgt[nmax];
ll sum[nmax];
int n,i,x,a,b,q,p;

void update(int p,int s,int d,int poz,int x)
{
    if(s!=d)
    {
        int m = (s+d)/2;
        if(poz<=m)
            update(p*2,s,m,poz,x);
        else
            update(p*2+1,m+1,d,poz,x);

        sum[p]=sum[p*2]+sum[p*2+1];

        lft[p]=max(lft[p*2],sum[p*2]+lft[p*2+1]);
        rgt[p]=max(rgt[p*2+1],sum[p*2+1]+rgt[p*2]);

        ans[p]=max(lft[p],max(rgt[p],max(ans[p*2],max(ans[p*2+1],lft[p*2+1]+rgt[p*2]))));
    }
    else
    if(s==poz)
        sum[p]=lft[p]=rgt[p]=ans[p]=x;
}

nod query(int p,int s,int d,int a,int b)
{
    nod z;
    int m = (s+d)/2;
    if(s==a && d==b)
    {
       z.lft=lft[p];
       z.rgt=rgt[p];
       z.ans=ans[p];
       z.sum=sum[p];
       return z;
    }
    else
    if(a>m)
        return query(p*2+1,m+1,d,a,b);
    else
    if(b<=m)
        return query(p*2,s,m,a,b);
    else
    if(s<=a && a<=m && m<b && b<=d)
    {
        nod x = query(p*2,s,m,a,m);
        nod y = query(p*2+1,m+1,d,m+1,b);

        z.sum=x.sum+y.sum;

        z.lft=max(x.lft,x.sum+y.lft);
        z.rgt=max(y.rgt,y.sum+x.rgt);

        z.ans=max(z.lft,max(z.rgt,max(x.ans,max(y.ans,y.lft+x.rgt))));

        return z;
    }
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>x;
        update(1,1,n,i,x);
    }
    fin>>q;
    while(q--)
    {
        fin>>x;
        switch(x)
        {
        case 0:
            fin>>i>>p;
            ++i;
            update(1,1,n,i,p);
            break;
        case 1:
            fin>>a>>b;
            ++a;
            ++b;
            nod ans = query(1,1,n,a,b);
            fout<<max(ans.ans,0LL)<<'\n';
            break;
        }
    }

}
