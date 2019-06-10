#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

ifstream fin("dreptpal.in");
ofstream fout("dreptpal.out");

int v[1010][1010];
int d[1010][1010];
int lim[1010][1010];
stack <int> s;
int n,m,i,j;
int ans;

void manacher(int x)
{
    int i,c=1,l,r;
    for(i=1; i<=m; ++i)
    {
        if(i<=c+d[x][c]/2)
            d[x][i]=min(d[x][c*2-i],(c-i+d[x][c]/2)*2+1);
        if(!d[x][i])
            d[x][i]=1;
        l=i-d[x][i]/2;
        r=i+d[x][i]/2;
        while(l>1 && r<m && v[x][r+1]==v[x][l-1])
        {
            ++r;
            --l;
            d[x][i]+=2;
        }
        if(i+d[x][i]/2>c+d[x][c]/2)
            c=i;
    }
}

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            fin>>v[i][j];
    for(i=1; i<=n; ++i)
        manacher(i);
    int mx=0;

    for(j=1; j<=m; ++j)
    {
        while(!s.empty())
            s.pop();
        s.push(0);
        for(i=1; i<=n; ++i)
        {
            while(!s.empty() && d[s.top()][j]>=d[i][j])
                s.pop();
            lim[i][j]=s.top();
            s.push(i);
        }
        s.push(n+1);
        for(i=n; i>0; --i)
        {
            while(!s.empty() && d[s.top()][j]>d[i][j])
                s.pop();
            lim[i][j]=s.top()-lim[i][j]-1;
            s.push(i);
        }
    }
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            ans=max(ans,d[i][j]*lim[i][j]);
    fout<<ans;
}
