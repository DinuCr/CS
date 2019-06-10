#include <cstdio>

using namespace std;

int v[1010],d[1010],r[1010];

int main()
{
    freopen("subsiruri.in","r",stdin);
    freopen("subsiruri.out","w",stdout);

    int mx=1,nr,i,j,n;

    scanf("%d",&n);
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&v[i]);
        d[i]=1;
        r[i]=1;
        for(j=1; j<i; ++j)
            if(v[j]<v[i])
            {
                if(d[j]>=d[i])
                {
                    d[i]=d[j]+1;
                    r[i]=r[j];
                }
                else if(d[j]+1==d[i])
                {
                    r[i]+=r[j];
                    r[i]%=9901;
                }
            }
        if(d[i]>mx)
        {
            mx=d[i];
            nr=r[i];
        }
        else if(d[i]==mx)
            nr+=r[i];
    }
    printf("%d\n%d",mx,nr%9901);
}
