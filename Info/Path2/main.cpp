#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax 110

ifstream fin("path2.in");
ofstream fout("path2.out");

vector <int> v[nmax];
int d1[nmax];
int d2[nmax];
int cnt1[nmax];
int cnt2[nmax];
int n,m,x,y,k;

void bf1(int x)
{
    queue <int> q;
    q.push(x);
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(auto it:v[x])
        {
            if(d1[x]+1>d1[it])
                continue;
            if(d1[it]==1e9)
                q.push(it);
            d1[it]=d1[x]+1;
            cnt1[it]+=cnt1[x];
        }
    }
}

void bf2(int x)
{
    queue <int> q;
    q.push(x);
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(auto it:v[x])
        {
            if(d2[x]+1>d2[it])
                continue;
            if(d2[it]==1e9)
                q.push(it);
            d2[it]=d2[x]+1;
            cnt2[it]+=cnt2[x];
        }
    }
}

vector <int> ans;

void build_path(int node,int ok)
{
    if(node==1 && ok==1)
    {
        for(int i=ans.size()-1; i>=0; --i)
            fout<<ans[i]<<' ';
        fout<<y<<'\n';
        ++k;
    }
    if(ok==0 && node==x)
        ok=1;
    if(ok==1)
    {
        for(auto it:v[node])
        {
            if(k>=100)
                break;
            if(d1[it]+1==d1[node])
                ans.push_back(it),build_path(it,ok),ans.pop_back();
        }
    }
    else
    {
        for(auto it:v[node])
        {
            if(k>=100)
                break;
            if(d2[it]+1==d2[node])
                ans.push_back(it),build_path(it,ok),ans.pop_back();
        }
    }
}

int main()
{
    int i;
    fin>>n>>m>>x>>y;
    for(i=1; i<=m; ++i)
    {
        int a,b;
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1; i<=n; ++i)
        d1[i]=d2[i]=1e9;
    cnt1[1]=1;
    d1[1]=0;
    bf1(1);
    cnt2[x]=cnt1[x];
    d2[x]=0;
    bf2(x);
    fout<<d1[x]+d2[y]<<'\n'<<cnt2[y]<<'\n';
    k = 0;
    build_path(y,0);
}
