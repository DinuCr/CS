#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define ll long long
#define nmax 105
#define modulo 1000000007

inline int mod(ll x)
{
    if(x>modulo)
        return x%modulo;
    return x;
}

char v[nmax][nmax];
ll d[nmax][nmax][2];
int n,m,i,j,k,a,dx[8]={0,0,1,1,1,-1,-1,-1},dy[8]={1,-1,1,0,-1,1,0,-1};

int main()
{
    string s;
    fin>>s>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            fin>>v[i][j];
            if(v[i][j]==s[0])
                d[i][j][0]=1;
        }
    for(k=1; k<s.length(); ++k)
    {
        for(i=1; i<=n; ++i)
            for(j=1; j<=m; ++j)
            {
                if(v[i][j]!=s[k])
                    continue;
                for(a=0; a<8; ++a)
                    d[i][j][1]+=d[i+dx[a]][j+dy[a]][0];
                d[i][j][1]=mod(d[i][j][1]);
            }
        for(i=1; i<=n; ++i)
            for(j=1; j<=m; ++j)
                d[i][j][0]=d[i][j][1],d[i][j][1]=0;
    }
    ll ans = 0;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            ans+=d[i][j][0];
    ans = mod (ans);
    fout<<ans;
}
