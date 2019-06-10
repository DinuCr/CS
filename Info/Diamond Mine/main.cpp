#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int collect_max(vector <vector <int> > v)
{
    int i,j;
    int d[101][101];
    int w[101][101];

    for(i=0; i<v.size(); ++i)
    {
        for(j=0; j<v[i].size(); ++j)
            w[i][j]=v[i][j];
    }

    memset(d,0,sizeof(d));
    for(i=0; i<v.size(); ++i)
    {
        for(j=0; j<v[i].size(); ++j)
        {
            if(v[i][j]==-1)
            {
                d[i][j]=-1;
                continue;
            }
            if(i>0 && j>0 && max(d[i][j-1],d[i-1][j])!=-1)
                d[i][j]=v[i][j]+max(d[i][j-1],d[i-1][j]);
            else
            if(i>0 && d[i-1][j]!=-1)
                d[i][j]=v[i][j]+d[i-1][j];
            else
            if(j>0 && d[i][j-1]!=-1)
                d[i][j]=v[i][j]+d[i][j-1];
            else
            if(i==0 && j==0)
            d[i][j]=v[i][j];
            else
            d[i][j]=-1;
        }
    }
    if(d[v.size()-1][v[0].size()-1]==-1)
        return 0;
    int n = v.size()-1, m = v[0].size()-1;
    int ans=d[n][m];
    int x = n;
    int y = m;
    while(x!=0 || y!=0)
    {
        if(x>0 && y>0)
        {
            if(d[x][y]==d[x-1][y]+v[x][y])
            {
                v[x][y]=0;
                --x;
            }
            else
            if(d[x][y]==d[x][y-1]+v[x][y])
            {
                v[x][y]=0;
                --y;
            }
        }
        else
        if(x>0)
        {
            --x;
            v[x][y]=0;
        }
        else
        {
            --y;
            v[x][y]=0;
        }
    }
    v[0][0]=0;
    memset(d,0,sizeof(d));
    for(i=n; i>=0; --i)
    {
        for(j=m; j>=0; --j)
        {
            if(v[i][j]==-1)
            {
                d[i][j]=-1;
                continue;
            }
            if(i<n && j<m && max(d[i][j+1],d[i+1][j])!=-1)
                d[i][j]=v[i][j]+max(d[i][j+1],d[i+1][j]);
            else
            if(i<n && d[i+1][j]!=-1)
                d[i][j]=v[i][j]+d[i+1][j];
            else
            if(j<m && d[i][j+1]!=-1)
                d[i][j]=v[i][j]+d[i][j+1];
            else
            if(i==n && j==m)
            d[i][j]=0;
            else
            d[i][j]=-1;
        }
    }
    ans+=d[0][0];
    int ans1=0;

    for(i=0; i<v.size(); ++i)
    {
        for(j=0; j<v[i].size(); ++j)
            v[i][j]=w[i][j];
    }

    memset(d,0,sizeof(d));
    for(i=0; i<v.size(); ++i)
    {
        for(j=0; j<v[i].size(); ++j)
        {
            if(v[i][j]==-1)
            {
                d[i][j]=-1;
                continue;
            }
            if(i>0 && j>0 && max(d[i][j-1],d[i-1][j])!=-1)
                d[i][j]=v[i][j]+max(d[i][j-1],d[i-1][j]);
            else
            if(i>0 && d[i-1][j]!=-1)
                d[i][j]=v[i][j]+d[i-1][j];
            else
            if(j>0 && d[i][j-1]!=-1)
                d[i][j]=v[i][j]+d[i][j-1];
            else
            if(i==0 && j==0)
            d[i][j]=v[i][j];
            else
            d[i][j]=-1;
        }
    }
    n = v.size()-1, m = v[0].size()-1;
    ans1=d[n][m];
    x = n, y = m;
    while(x!=0 || y!=0)
    {
        if(x>0 && y>0)
        {
            if(d[x][y]==d[x][y-1]+v[x][y])
            {
                v[x][y]=0;
                --y;
            }
            else
            if(d[x][y]==d[x-1][y]+v[x][y])
            {
                v[x][y]=0;
                --x;
            }
        }
        else
        if(x>0)
        {
            --x;
            v[x][y]=0;
        }
        else
        {
            --y;
            v[x][y]=0;
        }
    }
    v[0][0]=0;
    memset(d,0,sizeof(d));
    for(i=n; i>=0; --i)
    {
        for(j=m; j>=0; --j)
        {
            if(v[i][j]==-1)
            {
                d[i][j]=-1;
                continue;
            }
            if(i<n && j<m && max(d[i][j+1],d[i+1][j])!=-1)
                d[i][j]=v[i][j]+max(d[i][j+1],d[i+1][j]);
            else
            if(i<n && d[i+1][j]!=-1)
                d[i][j]=v[i][j]+d[i+1][j];
            else
            if(j<m && d[i][j+1]!=-1)
                d[i][j]=v[i][j]+d[i][j+1];
            else
            if(i==n && j==m)
            d[i][j]=0;
            else
            d[i][j]=-1;
        }
    }
    ans1+=d[0][0];


    return max(ans,ans1);
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector <vector <int> > v;
    for(i=1; i<=n; ++i)
    {
        vector <int> curr;
        for(j=1; j<=n; ++j)
        {
            int x;
            cin>>x;
            curr.push_back(x);
        }
        v.push_back(curr);
    }
    cout<<collect_max(v);
}
