#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("saracsaurege.in");
ofstream fout("saracsaurege.out");

int v[100010];
int n;

void build()
{
    for(int i=n-1; i>0; --i)
        v[i]=max(v[i<<1],v[i<<1|1]);
}

int compute(int ls,int ld)
{
    int ans = 0;
    for(ls+=n,ld+=n; ls<ld; ls>>=1,ld>>=1)
    {
        if(ls&1)
            ans=max(ans,v[ls++]);
        if(ld&1)
            ans=max(ans,v[--ld]);
    }
    return ans;
}

int main()
{
    int q;
    int i;
    fin>>n>>q;
    for(i=0; i<n; ++i)
        fin>>v[i+n];
    build();
    int a,b;
    while(q--)
    {
        fin>>a>>b;
        fout<<compute(a-1,b)<<'\n';
    }
}
