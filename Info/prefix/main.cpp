#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char s[1000010];
int p[1000010];

int main()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    int n,i,k,z,t,j,mx;
    scanf("%d",&t);
    for(z=0; z<t; ++z)
    {
        scanf("%s\n",&s);
        n=strlen(s);
        for(i=n; i>0; --i)
            s[i]=s[i-1];
        p[1]=0;
        ++n;
        mx=0;
        for(i=2; i<n; ++i)
        {
            k=p[i-1];
            while(k>0 && s[i]!=s[k+1])
                k=p[k];
            if(s[k+1]==s[i])
                p[i]=k+1;
        }
        for(i=1;i<=n;++i)
        if(p[i]==1)
            {
                k=i-1;
                j=i;
                while(p[j]+1==p[j+1])
                    j++;
                if((j-i+1) >=k)
                    mx=max(mx,k*(j/k));
            }
        printf("%d\n",mx);
        for(i=1; i<n; ++i)
            p[i]=0;
    }
}
