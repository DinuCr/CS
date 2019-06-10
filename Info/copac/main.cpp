#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("copac.in");
ofstream fout("copac.ok");

#define nmax (int)1e5+10

vector <int> v[nmax];
int d[nmax];
int mx[nmax];
int used[nmax];

void df(int x)
{
    used[x]=1;
    d[x]=1;
    for(auto it:v[x])
        if(!used[it])
        {
            df(it);
            d[x]+=d[it];
            mx[x]=max(mx[x],d[it]);
        }
}

int main()
{
    int n,i,a,b;
    fin>>n;
    for(i=1; i<n; ++i)
    {
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    df(1);
    int ok=0;
    for(i=1; i<=n; ++i)
        if(n-d[i]<=n/2 && mx[i]<=n/2 && !ok)
            fout<<i,ok=1;
        else
        if(n-d[i]<=n/2 && mx[i]<=n/2)
            fout<<'\n'<<i;
    if(!ok)
        fout<<"Winter is here!";
}
