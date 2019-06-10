#include <cstdio>
#include <vector>
using namespace std;
char s[301][301];
int v[301][301],k,n,m,c,mx,t;
bool viz[900010];
vector <int> l[900010];
int nr[900010],y[900010];
void f(int i,int j,char x)
{
    if(s[i][j]==x && i>=0 && j>=0 && j<m && i<n)
    {
        s[i][j]=0;
        v[i][j]=k;
        f(i+1,j,x);
        f(i-1,j,x);
        f(i,j+1,x);
        f(i,j-1,x);
    }
    return;
}
inline bool fin(int x,int e)
{
    for(int i=0; i<l[x].size(); ++i)
        if(l[x][i]==e)
            return 1;
    return 0;
}
void f2(int i,int j,int x)
{
    if(i<n && j<m && j>=0 && i>=0 && v[i][j]!=0)
    {
        if(v[i][j]==x)
        {
            ++c;
            v[i][j]=0;
            viz[x]=1;
            f2(i+1,j,x);
            f2(i-1,j,x);
            f2(i,j-1,x);
            f2(i,j+1,x);
        }
        else if(!fin(x,v[i][j]))
        {
            l[x].push_back(v[i][j]);
            l[v[i][j]].push_back(x);
        }
    }
}
void df(int x)
{
    if(viz[x])
    {
        viz[x]=0;
        y[c++]=x;
        int i;
        for(i=0; i<l[x].size(); ++i)
            df(l[x][i]);
    }
}
inline bool f2(int x)
{
    int i;
    for(i=0; i<c; ++i)
        if(y[i]==x)
            return 1;
    return 0;
}
void sterge(int x)
{
    int i,j;
    for(i=0; i<l[x].size(); ++i)
    {
        for(j=0; j<l[l[x][i]].size(); ++j)
            if(l[l[x][i]][j]==x)
            {
                swap(l[l[x][i]][j],l[l[x][i]][l[l[x][i]].size()-1]);
                l[l[x][i]].pop_back();
                break;
            }
    }
}
int main()
{
    int i,j,N;
    freopen("zone2.in","r",stdin);
    freopen("zone2.out","w",stdout);
    scanf("%d%d%d\n",&n,&m,&t);
    for(i=0; i<n; ++i)
        scanf("%s\n",&s[i]);
    for(i=0; i<n; ++i)
        for(j=0; j<m; ++j)
            if(s[i][j])
            {
                ++k;
                f(i,j,s[i][j]);
            }
    viz[0]=1;
    for(i=0; i<n; ++i)
        for(j=0; j<m; ++j)
            if(!viz[v[i][j]])
            {
                c=0;
                int q=v[i][j];
                viz[v[i][j]]=1;
                f2(i,j,v[i][j]);
                nr[q]=c;
            }
    int ok;
    for(i=1; i<k; ++i)
    if(viz[i])
    {
        c=0;
        df(i);
        ok=1;
        while(ok)
        {
            ok=0;
            for(j=0; j<c; ++j)
                if(l[y[j]].size()<t)
                {
                    sterge(y[j]);
                    swap(y[j],y[c-1]);
                    c--;
                    j--;
                    ok=1;
                }
        }
        N=0;
        for(j=0; j<c; ++j)
            N+=nr[y[j]];
        mx=max(mx,N);
    }
    printf("%d",mx);
}
