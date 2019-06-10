#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define nmax 100100

vector <int> s;
int v[nmax];
int d[nmax];
int n,i,j,k;

#define DIM 10000
char buff[DIM];
int poz=0;

void citeste(int &numar)
{
     numar = 0;
     while (buff[poz] < '0' || buff[poz] > '9')
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     }
}

int bs(int l,int r,int x)
{
    int ans=r+1;
    while(l<=r)
    {
        int m = (l+r)>>1;
        if(s[m]<x)
            ans=m,r=m-1;
        else
            l=m+1;
    }
    return ans;
}

int main()
{
    freopen("calcule.in","r",stdin);
    citeste(n);
    citeste(k);
    for(i=1; i<=n; ++i)
        citeste(v[i]);
    for(i=1; i<=n; ++i)
    {
        int j = bs(0,s.size()-1,v[i]);
        if(j==s.size())
            s.push_back(v[i]);
        else
            s[j]=v[i];
    }
    freopen("calcule.out","w",stdout);
    printf("%d\n",s.size());
    d[0]=1;
    int sum=0;
    int ans=0;
    for(i=1; i<=n; ++i)
    {
        sum+=v[i];
        if(sum>=k)
            sum%=k;
        ans+=d[sum];
        if(ans>=20011)
            ans%=20011;
        d[sum]++;
    }
    printf("%d",ans);
}
