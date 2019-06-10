#include <stdio.h>
#include <cstring>
using namespace std;
char s[10010];
typedef struct str
{
    char s[1010];
};
str v[100010];
int n,m,i,j;
int l[100010];
inline bool comp(int p0,int x)
{
    int i,j;
    for(i=p0+l[x]-1,j=0; i>=p0; --i,++j)
        if(s[i]!=v[x].s[j] && s[i]!=v[x].s[j]+32)
            return 0;
    return 1;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",&s);
    scanf("%d",&m);
    for(i=1; i<=m; i++)
    {
        scanf("%s",&v[i].s);
        l[i]=strlen(v[i].s);
    }
    i=0;
    while(i<n)
    {
        for(j=1; j<=m; ++j)
            if(comp(i,j))
            {
                i+=l[j];
                break;
            }
        printf("%s ",v[j].s);
    }
}
