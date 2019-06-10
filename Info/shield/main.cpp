#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("shield.in");
ofstream fout("shield.out");

#define nmax 1000010
#define f first
#define s second

int rgt[nmax];
int lft[nmax];
vector <int> h[nmax];

bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.s>b.s;
}

int main()
{
    int mx=0,n,l,i,a,b;
    fin>>n>>l;
    --l;
    for(i=1; i<=n; ++i)
    {
        fin>>a>>b;
        mx=max(mx,a);
        h[a].push_back(b);
    }
    lft[1]=rgt[1]=1;
    for(i=2; i<=mx; ++i)
    {
        rgt[i]=rgt[i-1]+1;
        lft[i]=lft[i-1]-1;
        for(auto it:h[i])
            lft[i]=max(lft[i],it-l),
            rgt[i]=min(rgt[i],it);
    }
    for(i=mx-1; i>0; --i)
    {
        rgt[i]=min(rgt[i+1]+1,rgt[i]);
        lft[i]=max(lft[i+1]-1,lft[i]);
    }
    int curr=1;
    for(i=2; i<=mx; ++i)
    {
        if(curr<lft[i])
        {
            ++curr;
            fout<<'R';
        }
        else
        if(curr>rgt[i])
        {
            --curr;
            fout<<'L';
        }
        else
        fout<<'S';
    }
}
