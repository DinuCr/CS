#include <cstdio>
#include <algorithm>
using namespace std;
long long Y[100000],l,L,q[17][55],b[7],c;
int v[15]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
void P(int m,int k,long long p,int S,int s)
{
    if(k==m)
    {
        if(S==s && p<=L && p>=l)
            Y[c++]=p;
    }
    else
    {
        int i;
        for(i=1; S+i<=s && p*q[b[k]][i]<=L; ++i)
            P(m,k+1,p*q[b[k]][i],S+i,s);
    }
}
void f(int k,int s)
{
    if(k<=6 && k>1)
        P(k,1,1,0,s);
    if(k<5)
    {
        int i;
        for(i=b[k-1]+1; s+v[i]<52 && i<16; ++i)
        {
            b[k]=i;
            f(k+1,s+v[i]);
        }

    }
}
int main()
{
    freopen("cumpanit.in","r",stdin);
    freopen("cumpanit.out","w",stdout);
    int i,j;
    for(i=0; i<16; ++i)
    {
        q[i][0]=1;
        for(j=1; q[i][j-1]*v[i]<=1e15 && j<53; ++j)
            q[i][j]=q[i][j-1]*v[i]*1LL;
    }
    scanf("%lld%lld",&l,&L);
    b[0]=-1;
    f(1,0);
    sort(Y,Y+c);
    for(i=0; i<c; ++i)
        printf("%lld\n",Y[i]);
}
