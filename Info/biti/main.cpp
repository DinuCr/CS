#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin("biti.in");
ofstream fout("biti.out");

int v[1050000][2];
int viz[1050000];
int ans[1050000],k;
int n,i,p[25];

void euler(int x)
{
    if(v[x][0]!=-1 && !viz[v[x][0]])
    {
        int p = v[x][0];
        viz[p]=1;
        v[x][0]=-1;
        euler(p);
        ans[++k]=x;
    }
    if(v[x][1]!=-1 && !viz[v[x][1]])
    {
        int p = v[x][1];
        v[x][1]=-1;
        viz[p]=1;
        euler(p);
        ans[++k]=x;
    }
}

int main()
{
    fin>>n;
    p[0]=1;
    for(i=1; i<=n; ++i)
        p[i]=p[i-1]<<1;
    int mat = p[n]-1;
    for(i=0; i<p[n]; ++i)
    {
        v[i][0] = (i<<1) & mat;
        v[i][1] = ( (i<<1) | 1) & mat;
    }
    stack <int> q;
    q.push(0);
    while(!q.empty())
    {
        int x = q.top();
        viz[x]=1;
        if(v[x][0]!=-1 && !viz[v[x][0]])
        {
            int p = v[x][0];
            viz[p]=1;
            v[x][0]=-1;
            q.push(p);
            continue;
        }
        else
        if(v[x][1]!=-1 && !viz[v[x][1]])
        {
            int p = v[x][1];
            v[x][1]=-1;
            viz[p]=1;
            q.push(p);
            continue;
        }
        q.pop();
        ans[++k]=x;
    }
    int b = 0;
    fout<<k+n-1<<'\n';
    for(i=0; i<n; ++i)
        fout<<'0';
    for(i=k-1; i>0; --i)
    {
        fout<<(ans[i]&1);
    }
}
