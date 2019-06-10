#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("order.in");
ofstream fout("order.out");

#define zeros(x) (x^(x-1))&x
#define nmax (int)3e4+10

int v[nmax],n,i;

inline void add(int x,int z)
{
    for(int i=x; i<=n; i+=zeros(i))
        v[i]+=z;
}

inline int query(int x)
{
    int ans = 0;
    for(int i=x; i>0; i-=zeros(i))
        ans+=v[i];
    return ans;
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        add(i,1);
    int curr = 1;
    for(i=1; i<=n; ++i)
    {
        int step = i,j;
        int k = query(n),last=query(curr);
        if(k-query(curr)<step)
        {
            step -= k-query(curr)+1;
            step %= k;
            last = 1;
        }
        curr = n;
        for(j=1; j<=n; j<<=1);
        for( ; j; j>>=1)
            if(curr-j>0 && query(curr-j)>=step+last)
                curr-=j;
        add(curr,-1);
        fout<<curr<<' ';
    }
}
