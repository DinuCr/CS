#include <cstdio>
#include <cstring>
using namespace std;
FILE *f=fopen("interesant.in","r");
FILE *g=fopen("interesant.out","w");
struct sir
{
    char s[5005];
    int l;
};
sir v[205];
int i,n,p,mx,k,sp[205],ok,j,m;
inline bool maimic(char a[],char b[])
{
    for(int i=0; i<mx; ++i)
        if(b[i]<a[i])
            return 1;
        else if(a[i]<b[i])
            return 0;
}
inline bool contine(int M,int m)
{
    int i,k=-1,j,ok;
    for(i=0; i<v[m].l; ++i)
    {
        ok=0;
        for(j=k+1; j<v[M].l; ++j)
            if(v[m].s[i]==v[M].s[j])
            {
                ok=1;
                k=j;
                break;
            }
        if(!ok)
            return 0;
    }
    return 1;
}
int main()
{
    fscanf(f,"%d%d",&p,&n);
    for(i=0; i<n; ++i)
    {
        fscanf(f,"%s",&v[i].s);
        v[i].l=strlen(v[i].s);
    }
    if(p==1)
    {
        for(i=0; i<n; ++i)
        {
            if(v[i].l>mx)
            {
                k=i;
                mx=v[i].l;
            }
        }
        for(i=k+1; i<n; ++i)
            if(v[i].l==mx)
            {
                if(maimic(v[k].s,v[i].s))
                    k=i;
            }
        fprintf(g,"%s",v[k].s);
    }
    else
    {
        for(i=0; i<n; ++i)
        {
            ok=1;
            for(j=0; j<n; ++j)
                if(j!=i && v[j].l>=v[i].l)
                {
                    if(contine(j,i))
                    {
                        ok=0;
                        break;
                    }
                }
            if(ok)
            {
                sp[m++]=i;
            }
        }
        fprintf(g,"%d\n",m);
        for(i=0; i<m; ++i)
            fprintf(g,"%s\n",v[sp[i]].s);
    }
}
