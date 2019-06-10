#include <iostream>

using namespace std;
long i,j,n,x;
struct zr
{
    long c,d;
};
zr d1[1100][1100],d2[1100][1100],w[1100][1100];
void drum(int i,int j,zr d[1100][1100])
{
    if(i>1 && d[i][j].c==d[i-1][j].c+w[i][j].c && d[i][j].d==d[i-1][j].d+w[i][j].d)
    {
        drum(i-1,j,d);
        cout<<'D';
    }
    else if(j>1 && d[i][j].c==d[i][j-1].c+w[i][j].c && d[i][j].d==d[i][j-1].d+w[i][j].d)
    {
        drum(i,j-1,d);
        cout<<'R';
    }
}
int main()
{
    cin>>n;
    int ok=0,x1,y1;
    for(i=2; i<=n; i++)
    {
        d1[i][0].c=d1[0][i].c=d1[n+1][i].c=d1[i][n+1].c=10000000;
        d1[i][0].d=d1[0][i].d=d1[n+1][i].d=d1[i][n+1].d=10000000;
        d2[i][0].c=d2[0][i].c=d2[n+1][i].c=d2[i][n+1].c=10000000;
        d2[i][0].d=d2[0][i].d=d2[n+1][i].d=d2[i][n+1].d=10000000;
    }
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            cin>>x;
            if(x==0)
                x1=i,y1=j,ok=1,w[i][j].c=1,w[i][j].d=0;
            while(x>0 && x%2==0)
            {
                x/=2;
                w[i][j].d++;
            }
            while(x>0 && x%5==0)
            {
                x/=5;
                w[i][j].c++;
            }
        }
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            if(d1[i-1][j].d<d1[i][j-1].d)
            {
                d1[i][j].c=d1[i-1][j].c+w[i][j].c;
                d1[i][j].d=d1[i-1][j].d+w[i][j].d;
            }
            else
            {
                d1[i][j].c=d1[i][j-1].c+w[i][j].c;
                d1[i][j].d=d1[i][j-1].d+w[i][j].d;
            }
        }
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            if(d2[i-1][j].c<d2[i][j-1].c)
            {
                d2[i][j].c=d2[i-1][j].c+w[i][j].c;
                d2[i][j].d=d2[i-1][j].d+w[i][j].d;
            }
            else
            {
                d2[i][j].c=d2[i][j-1].c+w[i][j].c;
                d2[i][j].d=d2[i][j-1].d+w[i][j].d;
            }
        }
    if(!ok)
    {
        if(min(d1[n][n].c,d1[n][n].d)<min(d2[n][n].c,d2[n][n].d))
        {
            cout<<min(d1[n][n].c,d1[n][n].d)<<'\n';
            drum(n,n,d1);
        }
        else
        {
            cout<<min(d2[n][n].c,d2[n][n].d)<<'\n';
            drum(n,n,d2);
        }
    }
    else
    {
        if(min(min(d1[n][n].c,d1[n][n].d),min(d2[n][n].c,d2[n][n].d))==0)
        {
            if(min(d1[n][n].c,d1[n][n].d)<min(d2[n][n].c,d2[n][n].d))
            {
                cout<<min(d1[n][n].c,d1[n][n].d)<<'\n';
                drum(n,n,d1);
            }
            else
            {
                cout<<min(d2[n][n].c,d2[n][n].d)<<'\n';
                drum(n,n,d2);
            }
        }
        else
        {
            cout<<"1\n";
            for(i=1;i<x1;i++)
            cout<<'D';
            for(i=1;i<y1;i++)
            cout<<'R';
            for(i=x1;i<n;i++)
            cout<<'D';
            for(i=y1;i<n;i++)
            cout<<'R';
        }
    }
}
