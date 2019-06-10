#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax (int) 1e6+10

int aib[nmax];
int v[nmax];

void update(int p,int x)
{
    for( ; p<=1e6; p+=((p^(p-1))&p))
        aib[p]+=x;
}

int query(int p)
{
    int ans = 0;
    for( ; p>0; p-=((p^(p-1))&p))
        ans+=aib[p];
    return ans;
}

int main()
{
    int n,m,k,i;
    cin>>n>>m>>k;
    --m;
    for(i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        v[x]=1;
        update(x,1);
    }
    int ans = 0;
    for(i=1; i+m<=1e6; ++i)
    {
        int l = query(i-1);
        int d = query(i+m)-l;
        if(d<k)
            continue;
        else
        {
            int j;
            int curr = i+m;
            for(j=1; j<=m; j<<=1);
            for( ; j>0; j>>=1)
                if(curr-j>=i && query(curr-j)>=k+l)
                    curr-=j;
            for(j = curr; d>=k; ++j)
                if(v[j])
                    v[j]=0,++ans,update(j,-1),--d;
        }
    }
    cout<<ans;
}
