#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("hotel.in");
ofstream fout("hotel.out");

#define nmax 1700000

int st[nmax];
int dr[nmax];
int ans[nmax];
int n,p,x,a,b;

void update1(int p,int s,int d,int a,int b)
{
    if(s==a && d==b)
    {
        st[p]=dr[p]=ans[p]=0;
        return ;
    }
    else
    {
        int f1 = p*2;
        int f2 = p*2+1;
        int m = (s+d)/2;

        if(ans[p]==0)
            ans[f1]=ans[f2]=st[f1]=st[f2]=dr[f1]=dr[f2]=0;
        if(ans[p]==d-s+1)
        {
            ans[f1]=dr[f1]=st[f1]=m-s+1;
            ans[f2]=dr[f2]=st[f2]=d-m;
        }
        if(a>m)
            update1(p*2+1,m+1,d,a,b);
        else
        if(b<=m)
            update1(p*2,s,m,a,b);
        else
        {
            update1(p*2,s,m,a,m);
            update1(p*2+1,m+1,d,m+1,b);
        }
        if(ans[f1]==m-s+1)
            st[p]=ans[f1]+st[f2];
        else
            st[p]=st[f1];
        if(ans[f2]==d-m)
            dr[p]=ans[f2]+dr[f1];
        else
            dr[p]=dr[f2];
        ans[p]=max(dr[p],max(st[p],max(ans[f1],max(ans[f2],st[f2]+dr[f1]))));
    }
}

void update0(int p,int s,int d,int a,int b)
{
    if(s==a && d==b)
    {
        st[p]=dr[p]=ans[p]=d-s+1;
        return ;
    }
    else
    {
        int f1 = p*2;
        int f2 = p*2+1;
        int m = (s+d)/2;

        if(ans[p]==0)
            ans[f1]=ans[f2]=st[f1]=st[f2]=dr[f1]=dr[f2]=0;
        if(ans[p]==d-s+1)
        {
            ans[f1]=dr[f1]=st[f1]=m-s+1;
            ans[f2]=dr[f2]=st[f2]=d-m;
        }
        if(a>m)
            update0(p*2+1,m+1,d,a,b);
        else
        if(b<=m)
            update0(p*2,s,m,a,b);
        else
        {
            update0(p*2,s,m,a,m);
            update0(p*2+1,m+1,d,m+1,b);
        }
        if(ans[f1]==m-s+1)
            st[p]=ans[f1]+st[f2];
        else
            st[p]=st[f1];
        if(ans[f2]==d-m)
            dr[p]=ans[f2]+dr[f1];
        else
            dr[p]=dr[f2];
        ans[p]=max(dr[p],max(st[p],max(ans[f1],max(ans[f2],st[f2]+dr[f1]))));
    }
}

int main()
{
    fin>>n>>p;
    ans[1]=st[1]=dr[1]=n;
    while(p--)
    {
        fin>>x;
        switch(x)
        {
        case 1:
            fin>>a>>b;
            b=a+b-1;
            update1(1,1,n,a,b);
            break;
        case 2:
            fin>>a>>b;
            b=a+b-1;
            update0(1,1,n,a,b);
            break;
        case 3:
            fout<<ans[1]<<'\n';
        }
    }
}
