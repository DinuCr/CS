#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

ifstream fin("euro3.in");
ofstream fout("euro3.out");

int ans[8010];
int d1[8010];
int d2[8010];
int v[4010];
int valmax,n;

void solve(int a[],int b[],int x)
{
    for(int i=1; i<=valmax; ++i)
    {
        b[i]=a[i];
        if(i>x)
            b[i]=max(b[i],a[i-x]);
        if(i==x)
            b[i]=x;
        if(b[i]!=0)
            ans[i]=min(ans[i],x-b[i]);
    }
}

int main()
{
    int t,i;
    fin>>t;
    while(t--)
    {
        fin>>n>>valmax;
        memset(ans, 0x3f, sizeof(ans));
        memset(d1, 0, sizeof(d1));
        for(i=1; i<=n; ++i)
            fin>>v[i];
        sort(v+1,v+n+1);
        for(i=1; i<=n; ++i)
            if(i&1)
                solve(d1,d2,v[i]);
            else
                solve(d2,d1,v[i]);
        for(i=1; i<=valmax; ++i)
            if(ans[i]>valmax)
                fout<<-1<<' ';
            else
                fout<<ans[i]<<' ';
        fout<<'\n';
    }
}
