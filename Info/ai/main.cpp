#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("ai.in");
ofstream g("ai.out");
typedef struct coord
{
    int x,y;
};
coord s[1005010];
int v[1010][1010],w[1010][1010],n,i,j,t1,t2,s1,s2,s3,s4,r1,r2,r3,r4,x,y,m,p,mx,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},k,nr,nr1,nr2,mn,i1,i2,n2,mn11=-1,mn22=-1,mn12=-1,mn21=-1,q1,q2,ok1,ok2;
float b,a;
int cmmdc(int a,int b)
{
int r;
if(b==0 || a==0)
    return 1;
r=a%b;
while(r)
{
a=b;
b=r;
r=a%b;
}
return b;
}
int main()
{
    f>>n;
    f>>t1>>t2>>s1>>s2>>s3>>s4>>r1>>r2>>r3>>r4>>k;
    v[t1][t2]=-1;
    n2=n;
    for(i=1;i<=n;i++)
    {
        v[i][0]=-1;
        v[n+1][i]=-1;
        v[0][i]=-1;
        v[i][n+1]=-1;
        w[i][0]=-1;
        w[n+1][i]=-1;
        w[0][i]=-1;
        w[i][n+1]=-1;
    }
    for(i=1;i<=k;i++)
    {
        f>>x>>y;
        v[x][y]=-1;
    }
    for(i=1;i<=n;i++)
    {
    for(j=2;j<=n;j++)
    {
        if(v[i][j]==v[i][j-1] && v[i][j]==-1)
            nr++;
        else
        {
            mx=max(nr,mx);
            nr=1;
        }
    }
    mx=max(nr,mx);
    nr=1;
    }
    mx=max(nr,mx);
    for(j=1;i<=n;j++)
    {
    for(i=2;j<=n;i++)
    {
        if(v[i][j]==v[i-1][j] && v[i][j]==-1)
            nr++;
        else
        {
            mx=max(nr,mx);
            nr=1;
        }
    }
    mx=max(nr,mx);
    nr=1;
    }
    mx=max(nr,mx);
    g<<mx<<'\n';

    v[s1][s2]=1;
    v[s3][s4]=2;

    nr1=abs(t1-s1);
    nr2=abs(t2-s2);
    if(t1>s1)
        i1=1;
    else
        i1=-1;
    if(t2>s2)
        i2=1;
    else
        i2=-1;
    q1=(nr1/cmmdc(nr1,nr2))*i1;
    q2=(nr2/cmmdc(nr1,nr2))*i2;
    a=s1;
    b=s2;
    while(a!=t1 && b!=t2)
    {
        x=a;
        y=b;
        if(v[x][y]==0)
        {
            v[x][y]=1;
        }
        a+=q1;
        b+=q2;
    }
    nr1=abs(t1-s3);
    nr2=abs(t2-s4);
    if(t1>s3)
        i1=1;
    else
        i1=-1;
    if(t2>s4)
        i2=1;
    else
        i2=-1;
    q1=(nr1/cmmdc(nr1,nr2))*i1;
    q2=(nr2/cmmdc(nr1,nr2))*i2;
    a=s3;
    b=s4;
    while(a!=t1 && b!=t2)
    {
        x=a;
        y=b;
        if(v[x][y]==0)
        {
            v[x][y]=2;
        }
        a+=q1;
        b+=q2;
    }
    n=1;
    s[n].x=r1;
    s[n].y=r2;
    w[s[n].x][s[n].y]=1;ok1=1;ok2=1;
    for(i=1;i<=n &&(mn11==-1 || mn12==-1);i++)
    {
        if(v[s[i].x][s[i].y]==1 && ok1)
        {
            mn11=w[s[i].x][s[i].y]-1;
            ok1=0;
        }
        if(v[s[i].x][s[i].y]==2 && ok2)
        {
            mn12=w[s[i].x][s[i].y]-1;
            ok2=0;
        }
        for(k=0;k<4;k++)
        if(v[s[i].x+dx[k]][s[i].y+dy[k]]!=-1 && w[s[i].x+dx[k]][s[i].y+dy[k]]==0)
        {
            w[s[i].x+dx[k]][s[i].y+dy[k]]=w[s[i].x][s[i].y]+1;
            n++;
            s[n].x=s[i].x+dx[k];
            s[n].y=s[i].y+dy[k];
        }
    }
    for(i=1;i<=n2;i++)
    {
        for(j=1;j<=n2;j++)
            cout<<v[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
    for(i=1;i<=n2;i++)
    {
        for(j=1;j<=n2;j++)
            cout<<w[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
    n=1;
    s[n].x=r3;
    s[n].y=r4;
    w[s[n].x][s[n].y]=-1;ok1=1;ok2=1;
    for(i=1;i<=n && (mn21==-1 || mn22==-1);i++)
    {
        if(v[s[i].x][s[i].y]==1 && ok1)
        {
            mn21=-w[s[i].x][s[i].y]+1;
            ok1=0;
        }
        if(v[s[i].x][s[i].y]==2 && ok2)
        {
            mn22=-w[s[i].x][s[i].y]+1;
            ok2=0;
        }
        for(k=0;k<4;k++)
        if(v[s[i].x+dx[k]][s[i].y+dy[k]]!=-1 && w[s[i].x+dx[k]][s[i].y+dy[k]]>=0)
        {
            w[s[i].x+dx[k]][s[i].y+dy[k]]=w[s[i].x][s[i].y]-1;
            n++;
            s[n].x=s[i].x+dx[k];
            s[n].y=s[i].y+dy[k];
        }
    }
    for(i=1;i<=n2;i++)
    {
        for(j=1;j<=n2;j++)
            cout<<w[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
    if(mn11==-1)
        mn11=n2*n2+1;
    if(mn12==-1)
        mn12=n2*n2+1;
    if(mn21==-1)
        mn21=n2*n2+1;
    if(mn22==-1)
        mn22=n2*n2+1;

    g<<min(max(mn11,mn22),max(mn12,mn21));
}
