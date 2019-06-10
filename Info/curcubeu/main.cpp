#include <stdio.h>
#include <fstream>

using namespace std;

#define nmax 1000100

int a[nmax];
int b[nmax];
int c[nmax];
int ans[nmax];
int ne[nmax];
int i,s,d,col,n,j;

int main()
{
    freopen("curcubeu.in","r",stdin);
    freopen("curcubeu.out","w",stdout);
    scanf("%d%d%d%d",&n,&a[1],&b[1],&c[1]);
    for(i=2; i<n; ++i)
    {
        a[i]=(1LL*a[i-1]*i)%n;
        b[i]=(1LL*b[i-1]*i)%n;
        c[i]=(1LL*c[i-1]*i)%n;
    }
    for(i=1; i<n; ++i)
        ne[i]=i;
    for(i=n-1; i>0; --i)
    {
        s=a[i];
        d=b[i];
        col=c[i];
        if(s>d)
            swap(s,d);
        for(j=s; j<=d; ++j)
        if(!ans[j])
        {
            ans[j]=col;
            ne[j]=d;
        }
        else
        j=ne[j];
    }
    for(i=1; i<n; ++i)
       printf("%d\n",ans[i]);
}
