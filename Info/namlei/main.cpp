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

#define nmax 650000

mat v[nmax];

mat curr;

int n,k,x,y;
int i,j,cnt,w,jj,q,qq;

void multiply(mat &ans,mat a,mat b)
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

void build()
{
    for(i=n-1; i>0; --i)
        multiply(v[i],v[i<<1],v[i<<1|1]);
}

void update(int p)
{
    for(v[p+=n]=curr; p>1; p>>=1)
        if(p&1)
            multiply(v[p>>1],v[p^1],v[p]);
        else
            multiply(v[p>>1],v[p],v[p^1]);
}

void query(int a,int b)
{
    mat dr;
    for(int i=0; i<k; ++i)
        for(int j=0; j<k; ++j)
            dr.d[i][j]=(i==j);
    for(a+=n, b+=n; a<b; a>>=1, b>>=1)
    {
        if(a&1)
            multiply(curr,curr,v[a++]);
        if(b&1)
            multiply(dr,v[--b],dr);
    }
    multiply(curr,curr,dr);
}

int main()
{
    fin>>n>>k>>x>>y;

    for(i=0; i<n; ++i)
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
        v[i+n]=curr;
    }

    build();

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

            query(a,c);

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

            update(a);

            break;
        }
    }
}
