#include <cstdio>
#include <algorithm>

using namespace std;
struct z
{
    char s[6];
}v[400010];
bool c[200][200];
char s[13];
int n,p;

bool compare(z a,z b)
{
    int i;
    for(i=0; i<6; ++i)
        if(c[a.s[i]][b.s[i]])
            return 1;
        else
        if(c[b.s[i]][a.s[i]])
            return 0;
    return 0;
}
bool d(char a[6],char b[6])
{
    if(a[0]!=b[0] || a[1]!=b[1] || a[2]!=b[2] || a[3]!=b[3] || a[4]!=b[4])
        return 1;
    return 0;
}
int main()
{
    freopen("zimeria.in","r",stdin);
    freopen("zimeria.out","w",stdout);
    scanf("%d%d\n",&p,&n);
    scanf("%s\n",&s);
    int i,j;
    for(i=0; i<12; ++i)
        for(j=i+1; j<12; ++j)
                c[s[i]][s[j]]=1;
    for(i=0;i<n;++i)
        scanf("%s\n",&v[i]);
    sort(v,v+n,compare);
    if(p==2)
        for(i=0; i<n; ++i)
            printf("%s\n",v[i].s);
    else
    {
        int nr=1;
        for(i=1; i<n; ++i)
            if(d(v[i].s,v[i-1].s))
                ++nr;
        printf("%d",nr);
    }
}
