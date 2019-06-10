#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("subset.in");
ofstream fout("subset.out");

#define nmax (int)1e3+10

int v[nmax];
int d[nmax];

int main()
{
    int i,n;
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
    }
    sort(v+1,v+n+1);
    int ans = 0;
    d[n]=1;
    for(i=n-1; i>0; --i)
    {
        d[i]=1;
        for(int j=i+1; j<=n; ++j)
            if(v[j]%v[i]==0)
                d[i]=max(d[i],d[j]+1);
        ans=max(ans,d[i]);
    }
    fout<<ans;
}
