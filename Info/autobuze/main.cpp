#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

ifstream fin("autobuze.in");
ofstream fout("autobuze.out");

#define valmax 10010
#define nmax 50010
#define f first
#define s second
#define mp make_pair

pair<int,int> curr[20];
unordered_map<int,int> v;
int t[nmax];
int q[nmax];
int prime[10005];
bool w[10005];
int n,i,j,k,cnt,nr;

int root(int x)
{
    if(!t[x])
        return x;
    t[x]=root(t[x]);
    return t[x];
}

void bkt(int sum,int j)
{
    if(j==k+1)
    {
        if(sum==1)
            return ;
        int x = sum;
        if(v[x]!=0)
        {
            if(root(v[x])!=root(nr))
            {
                --cnt;
                t[root(v[x])]=root(nr);
            }
        }
    }
    else
    {
        for(int i=0; i<=curr[j].s; ++i)
        {
            bkt(sum,j+1);
            sum*=curr[j].f;
        }
    }
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>q[i];
        v[q[i]]=i;
    }
    for(i=4; i<10000; i+=2)
        w[i]=1;
    for(i=3; i<100; i+=2)
        if(!w[i])
        {
            for(j=i*i; j<10000; j+=i)
                w[j]=1;
        }
    for(i=2; i<10000; ++i)
        if(!w[i])
            prime[++k]=i;
    cnt = n;
    for(i=1; i<=n; ++i)
    {
        int z = sqrt(q[i]);

        k=0;
        for(j=1; prime[j]<=z; ++j)
        {
            if(q[i]%prime[j]==0)
            {
                curr[++k].f=prime[j];
                q[i]/=prime[j];
                curr[k].s=1;
                while(q[i]%prime[j]==0)
                {
                    q[i]/=prime[j];
                    curr[k].s++;
                }
            }
        }
        if(q[i]>1)
        {
            curr[++k].f=q[i];
            curr[k].s=1;
        }
        nr=i;
        bkt(1,1);
    }
    fout<<cnt;
}
