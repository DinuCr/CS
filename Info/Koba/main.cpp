/*#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("koba.in");
ofstream fout("koba.out");

int f;
int v[1000];
int s[1000];

inline int num(int a,int b,int c)
{
    return a*100+b*10+c;
}

int main()
{
    int a,b,c,n,i,d,ans=0,nrec,rec;
    fin>>n>>a>>b>>c;
    a%=10,b%=10,c%=10;
    v[num(a,b,c)]=3;
    if(n==1)
        fout<<a;
    if(n==2)
        fout<<a+b;
    if(n==3)
        fout<<a+b+c;
    if(n<=3)
        return 0;
    ans = a+b+c;
    for(i=4; i<=n; ++i)
    {
        d = (c+b*a)%10;
        ans+=d;
        if(v[num(b,c,d)])
        {
            rec = i-v[num(b,c,d)]+1;
            n-=i;
            nrec = ans - s[num(b,c,d)];
            ans+=(n/rec)*nrec;
            n%=rec;
            break;
        }
        else
        v[num(b,c,d)]=i,s[num(b,c,d)]=ans;
        a=b,b=c,c=d;
    }
    a=b,b=c,c=d;
    for(i=1 ; i<=n; ++i)
    {
        d = (c+b*a)%10;
        ans+=d;
        a=b,b=c,c=d;
    }
    fout<<ans;
}*/
#include<cstdio>
int ma[11][11][11];
int v[2001];
int main ()
{freopen ("koba.in","r",stdin);
freopen ("koba.out","w",stdout);
int n,i,x,y,z,t,s,k,pp;
scanf("%d%d%d%d",&n,&x,&y,&z);
x%=10;
y%=10;
z%=10;
ma[10][10][x]=1;
ma[10][x][y]=2;
ma[x][y][z]=3;
v[1]=x;
v[2]=v[1]+y;
v[3]=v[2]+z;
pp=1;
k=3;
for(i=4;i<=n&&pp==1;i++)
    {t=(x*y+z)%10;
    x=y;
    y=z;
    z=t;
    if(ma[x][y][z]>0)
        pp=0;
    else
        {k++;
        v[k]=v[k-1]+t;
        ma[x][y][z]=i;
        }
    }
n-=ma[x][y][z]-1;
s=v[ma[x][y][z]-1];
s+=(n/(k-ma[x][y][z]+1))*(v[k]-v[ma[x][y][z]-1]);
s+=v[n%(k-ma[x][y][z]+1)+ma[x][y][z]-1]-v[ma[x][y][z]-1];
printf("%d",s);
return 0;
}
