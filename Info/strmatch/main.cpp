#include <cstring>
#include <cstdio>

using namespace std;

int n,N,p[2000010],r[2000010];
char s[2000010],S[2000010];

void phi()
{
    int i,k;
    p[1]=0;
    for(i=2; i<n; ++i)
    {
        k=p[i-1];
        while(k>0 && s[k+1]!=s[i])
            k=p[k];
        if(s[k+1]==s[i])
            p[i]=k+1;
    }
}

int main()
{
    freopen("strmatch.in","r",stdin);
    freopen("strmatch.out","w",stdout);
    scanf("%s\n%s",&s,&S);

    int i,k,nr=0;

    n=strlen(s);
    N=strlen(S);

    for(i=n; i>0; --i)
        s[i]=s[i-1];
    for(i=N; i>0; --i)
        S[i]=S[i-1];

    ++N;
    ++n;

    phi();

    --n;
    for(i=1; i<N; ++i)
    {
        k=r[i-1];
        while(k>0 && S[i]!=s[k+1])
            k=p[k];
        if(S[i]==s[k+1])
            r[i]=k+1;
        if(r[i]==n)
            ++nr;
    }
    printf("%d\n",nr);
    nr=1000;
    for(i=1; i<N && nr; ++i)
        if(r[i]==n)
        {
            --nr;
            printf("%d ",i-n);
        }
}
