#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("confuzie.in");
ofstream fout("confuzie.out");

#define nmax 200010

vector <int> v[nmax];
int sum[nmax<<2];
int best[nmax<<2];
int poz[nmax<<2];
int first[nmax];
int last[nmax];
int k;

void df(int x,int t)
{
    first[x]=k++;
    for(auto it:v[x])
        if(it!=t)
            df(it,x);
    last[x]=k++;
}

inline void update(int x)
{
    for(x>>=1; x; x>>=1)
    {
        sum[x]=sum[x<<1]+sum[x<<1|1];
        if(best[x<<1]>=best[x<<1|1]+sum[x<<1])
            best[x]=best[x<<1],poz[x]=poz[x<<1];
        else
            best[x]=best[x<<1|1]+sum[x<<1],poz[x]=poz[x<<1|1];
    }
}

inline int compute_sum(int a,int b)
{
    int ans = 0;
    for( ; a<b; a>>=1,b>>=1)
    {
        if(a&1)
            ans+=sum[a++];
        if(b&1)
            ans+=sum[--b];
    }
    return ans;
}

int solve(int a,int b,int suma)
{
    int lft = 0;
    vector <int> curr;
    for( ; a<b; a>>=1,b>>=1)
    {
        if(a&1)
        {
            if(best[a]+lft==suma)
                return poz[a];
            lft+=sum[a];
            ++a;
        }
        if(b&1)
        {
            --b;
            curr.push_back(b);
        }
    }
    for(int i=curr.size()-1; i>=0; --i)
    {
        if(best[curr[i]]+lft==suma)
            return poz[curr[i]];
        lft+=sum[curr[i]];
    }
}

#define DIM 10000
char buff[DIM];
int po=0;

inline void citeste(int &numar)
{
     numar = 0;
     while (buff[po] < '0' || buff[po] > '9')
          if (++po == DIM)
               fin.read(buff,DIM),po=0;
     while ('0'<=buff[po] && buff[po]<='9')
     {
          numar = numar*10 + buff[po] - '0';
          if (++po == DIM)
               fin.read(buff,DIM),po=0;
     }
}

int main()
{
    int a,b,n,q,i,suma;
    citeste(n);
    citeste(q);
    for(i=1; i<n; ++i)
    {
        citeste(a);
        citeste(b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    df(1,0);
    n<<=1;
    for(i=1; i<=n; ++i)
        poz[first[i]+n]=i,poz[last[i]+n]=i;
    int p;
    while(q--)
    {
        citeste(p);
        if(p==0)
        {
            citeste(a);
            if(sum[first[a]+n]==-1)
                sum[first[a]+n]=0,sum[last[a]+n]=0,
                best[first[a]+n]=0,best[last[a]+n]=0;
            else
                sum[first[a]+n]=-1,sum[last[a]+n]=1,
                best[first[a]+n]=-1,best[last[a]+n]=1;
            update(first[a]+n);
            update(last[a]+n);
        }
        else
        {
            citeste(a);
            citeste(b);
            suma = compute_sum(last[b]+n,last[a]+n+1);
            if(!suma)
                fout<<"-1\n";
            else
                fout<<solve(last[b]+n,last[a]+n+1,suma)<<'\n';
        }
    }
}
