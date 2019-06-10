#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("namlei.in");
ofstream fout("namlei.out");

const int mod = 997;

struct mat
{
    int d[8][8];
};

#define nmax 5510000

mat v[nmax];

mat curr;

int n,k,x,y;
int i,j,cnt,w,jj,q,qq;

void multiply(mat &ans,const mat &a,const mat &b)
{
    int i,j,c;

    for(i=0; i<k; ++i)
        for(j=0; j<k; ++j)
            ans.d[i][j]=0;

    for(i=0; i<k; ++i)
        for(c=0; c<k; ++c)
            for(j=0; j<k; ++j)
                ans.d[i][j]+=a.d[i][c]*b.d[c][j];

    for(i=0; i<k; ++i)
        for(j=0; j<k; ++j)
            if(ans.d[i][j]>996)
                ans.d[i][j]%=mod;
}

void update(int p,int l,int r,int x)
{
    while(l!=r)
    {
        int m = (l+r)>>1;
        if(x<=m)
            p<<=1,r=m;
        else
        {
            p<<=1;
            ++p;
            l=m+1;
        }
    }
    v[p]=curr;
    p>>=1;
    for( ; p; p>>=1)
        multiply(v[p],v[p<<1],v[(p<<1)+1]);
}

void add_to_ans(mat x)
{
    int i,j,c;
    mat y;
    y=curr;

    for(i=0; i<k; ++i)
        for(j=0; j<k; ++j)
            curr.d[i][j]=0;

    for(i=0; i<k; ++i)
        for(c=0; c<k; ++c)
            for(j=0; j<k; ++j)
                curr.d[i][j]+=x.d[i][c]*y.d[c][j];

    for(i=0; i<k; ++i)
        for(j=0; j<k; ++j)
            if(curr.d[i][j]>996)
                curr.d[i][j]%=mod;
}

void query(int p,int l,int r,int a,int b)
{
    if(a<=l && r<=b)
    {
        add_to_ans(v[p]);
        return;
    }
    int m = (l+r)>>1;
    if(b>m)
        query((p<<1)+1,m+1,r,a,b);
    if(a<=m)
        query(p<<1,l,m,a,b);
}

int main()
{
    fin>>n>>k>>x>>y;

    for(i=1; i<=n; ++i)
    {
        fin>>cnt>>j>>q;

        for(int o=0; o<k; ++o)
            for(int p=0; p<k; ++p)
                curr.d[o][p]=1;

        ++curr.d[j][q];
        for(w=1; w<cnt; ++w)
        {
            jj = (j * x + q * w * y);
            if(jj>=k)
                jj%=k;
            qq = (j * w * x + q * y);
            if(qq>=k)
                qq%=k;
            ++curr.d[jj][qq];
            j=jj;
            q=qq;
        }
        update(1,1,n,i);
    }
    char ch;

    int a,b,c,d;
    while(fin>>ch)
    {
        switch(ch)
        {
        case 'Q':
            fin>>a>>b>>c>>d;

            for(int ii=0; ii<k; ++ii)
                for(int jj=0; jj<k; ++jj)
                    curr.d[ii][jj]=(ii==jj);

            query(1,1,n,a+1,c);

            fout<<curr.d[b][d]<<'\n';

            break;
        default:
            fin>>a>>cnt>>j>>q;

            for(int o=0; o<k; ++o)
                for(int p=0; p<k; ++p)
                    curr.d[o][p]=1;

            ++curr.d[j][q];

            for(w=1; w<cnt; ++w)
            {
                jj= (j * x + q * w * y + 1);
                if(jj>=k)
                    jj%=k;
                qq= (j * w * x + q * y + 1);
                if(qq>=k)
                    qq%=k;
                ++curr.d[jj][qq];
                j=jj;
                q=qq;
            }

            update(1,1,n,a+1);

            break;
        }
    }
}
